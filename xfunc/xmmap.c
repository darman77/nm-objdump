/*
** xmmap.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 12:48:10 2011 damien locque
** Last update Mon Mar  7 19:06:13 2011 damien locque
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include "my_objdump.h"
#include "xfunc.h"

void		*xmmap(int fd, char *pathname)
{
  void		*res;

  if (((res = mmap(NULL, filesize(fd), PROT_READ,
		  MAP_SHARED, fd, (off_t)0))) == (void*)-1)
    {
      fprintf(stderr, "%s: %s\n", pathname, strerror(errno));
      return ((void *)-1);
    }
  return (res);
}
