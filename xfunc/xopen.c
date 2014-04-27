/*
** xopen.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 12:46:06 2011 damien locque
** Last update Fri Mar  4 13:25:36 2011 damien locque
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "xfunc.h"

int		xopen(const char *pathname, int flags)
{
  int		ret;

  if ((ret = open(pathname, flags)) == -1)
    {
      fprintf(stderr, "%s: %s\n", pathname, strerror(errno));
      return (-1);
    }
  return (ret);
}
