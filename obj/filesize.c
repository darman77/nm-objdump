/*
** filesize.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 17:54:23 2011 damien locque
** Last update Fri Mar  4 17:55:46 2011 damien locque
*/

#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_objdump.h"

off_t		filesize(int fd)
{
  off_t		res;

  if ((res = lseek(fd, 0, SEEK_END)) == ((off_t)-1))
    {
      fprintf(stderr, "%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (res);
}
