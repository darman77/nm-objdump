/*
** xclose.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 12:47:32 2011 damien locque
** Last update Fri Mar  4 12:57:00 2011 damien locque
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "xfunc.h"

int		xclose(int fd)
{
  int		ret;

  if ((ret = close(fd)) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (ret);
}
