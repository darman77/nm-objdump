/*
** nm.h for  in /home/locque_d//rendu/proj/nm
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Mar  7 18:55:28 2011 damien locque
** Last update Sun Mar 13 22:19:09 2011 damien locque
*/

#ifndef _MY_NM_H_
#define _MY_NM_H_

#include <elf.h>

typedef struct s_info
{
  void		*data;
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*shdr;
  char		*strtab;
} t_info;

typedef struct	s_list
{
  Elf32_Sym     *sym;
  struct s_list	*next;
}		t_list;

typedef struct s_sym
{
  char		symtype;
  unsigned int	symattr;
  unsigned int	symflag;
}t_sym;

void		add_list(t_list **list, Elf32_Sym *sym);
int		sort_list(t_info *info, t_list **list);
char		get_type(t_list *chunk, Elf32_Shdr *shdr);
void		print_content(t_info *info, t_list *list, Elf32_Shdr *shdr);
void		get_content(t_info *info, Elf32_Shdr *shdr);
void		print_nm(t_info *info);

#endif /* !_MY_NM_H_ */

