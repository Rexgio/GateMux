#include "spawn.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(void) {
  i32 master;
  char name[100];
  struct winsize winp;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &winp) == -1) {
    perror("ioctl");
    return 1;
  }

  pid_t pid = spawnPTY(&master, name, &winp);

  if (pid == -1) {
    return 1;
  }

  if (pid == 0) {
    execl("/bin/bash", "bash", (char *)NULL);

    perror("execl");
    _exit(127);
  }

  printf("child: %d\n", pid);
  printf("slave: %s\n", name);

  while (1) {
  }

  close(master);

  return 0;
}
