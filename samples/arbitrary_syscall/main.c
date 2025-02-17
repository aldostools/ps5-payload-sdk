/* Copyright (C) 2023 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>


int main() {
  int pid;

  //getpid()
  asm("movq $20, %%rax \n"
      "syscall \n"
      "movl %%eax, %0 \n"
      : "=r"(pid)
      :
      : "rax");

  printf("pid: %d\n", pid);

  return 0;
}
