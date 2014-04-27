/*
** xfunc.h for  in /home/locque_d//rendu/proj/nm/obj/xfunc
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 12:49:09 2011 damien locque
** Last update Mon Mar  7 19:05:55 2011 damien locque
*/

#ifndef _X_FUNC_H_
#define _X_FUNC_H_

#include <sys/mman.h>

int		xopen(const char *pathname, int flags);
int		xclose(int fd);
void		*xmmap(int fd, char *pathname);

#endif /* !_X_FUNC_H_ */
