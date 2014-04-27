/*
** nm_list.c for  in /home/locque_d//rendu/proj/nm/nm
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Mar 13 20:28:34 2011 damien locque
** Last update Sun Mar 13 22:19:40 2011 damien locque
*/

#include <elf.h>
#include <stdlib.h>
#include "my_nm.h"

void		add_list(t_list **list, Elf32_Sym *sym)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return;
  new->next = NULL;
  new->sym = sym;
  if (!list)
    (*list) = new;
  else
    {
      new->next = (*list);
      (*list) = new;
    }
}

int		sort_list(t_info *info, t_list **list)
{
  t_list	*tmp;
  int		flag;
  Elf32_Sym	*save;

  flag = 0;
  tmp = (*list);
  while (tmp)
    {
      if (tmp && tmp->next &&
	  strcmp(&(info->strtab[tmp->sym->st_name]),
		 &(info->strtab[tmp->next->sym->st_name])) > 0)
	{
	  save = tmp->sym;
	  tmp->sym = tmp->next->sym;
	  tmp->next->sym = save;
	  flag = 1;
	}
      tmp = tmp->next;
    }
  return (flag);
}

