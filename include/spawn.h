#ifndef SPAWN_H
#include "base.h"
#include <pty.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>

pid_t spawnPTY(int *master, char name[100], const struct winsize *winp);

#endif // !SPAWN_H
