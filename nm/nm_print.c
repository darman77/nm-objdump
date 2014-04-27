/*
** nm_print.c for  in /home/locque_d//rendu/proj/nm/nm
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Mar 13 20:28:00 2011 damien locque
** Last update Sun Mar 13 23:04:28 2011 damien locque
*/

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_nm.h"

void		print_content(t_info *info, t_list *list, Elf32_Shdr *shdr)
{
  t_list	*tmp;
  char		type;

  type = 'U';
  tmp = list;
  while (tmp)
    {
      type = get_type(tmp, shdr);
      if (tmp->sym->st_value && type != 'U')
	printf("%08x ", tmp->sym->st_value);
      else
	printf("         ");
      printf("%c ", type);
      printf("%s\n", &(info->strtab[tmp->sym->st_name]));
      tmp = tmp->next;
    }
}

void		get_content(t_info *info, Elf32_Shdr *shdr)
{
  Elf32_Sym	*start;
  Elf32_Sym	*end;
  Elf32_Sym	*tmp;
  t_list	*list;

  list = NULL;
  start = (Elf32_Sym *)(info->data + shdr->sh_offset);
  info->strtab = (char *)((char *)info->data
			  + info->shdr[shdr->sh_link].sh_offset);
  tmp = (Elf32_Sym*)((char *)info->data + shdr->sh_offset);
  end = (Elf32_Sym*)((char *)info->data + shdr->sh_offset + shdr->sh_size);
  while (tmp != end)
    {
      if (info->strtab[tmp->st_name] && ((tmp->st_info & 15) != STT_FILE))
	add_list(&list, tmp);
      tmp++;
    }
  while (sort_list(info, &list) == 1)
    ;
  print_content(info, list, &info->shdr[start->st_shndx]);
}

void		print_nm(t_info *info)
{
  int		i;

  i = 0;
  while (i < info->elf->e_shnum)
    {
      if (info->shdr[i].sh_type == SHT_SYMTAB)
	get_content(info, &info->shdr[i]);
      i++;
    }
}
