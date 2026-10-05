#include "base.h"
#include <pty.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>

// forkpty

pid_t spawnPTY(i32 *master, char *name, const struct winsize *winp) {
  // const struct termios termp;
  // For now no customizacion

  pid_t pid = forkpty(master, name, NULL, winp);

  if (pid == -1) {
    perror("forkpty");
    return -1;
  }

  return pid;
}
