/*
** objdump.h for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 17:49:22 2011 damien locque
** Last update Mon Mar  7 19:03:04 2011 damien locque
*/

#ifndef _MY_OBJDUMP_H_
#define _MY_OBJDUMP_H_

#include <elf.h>

typedef struct s_info
{
  void		*data;
  Elf32_Ehdr	*elf;
  Elf32_Shdr	*shdr;
  char		*strtab;
} t_info;

off_t		filesize(int fd);
void		print_header(t_info *info, char *pathname);
void		print_hexa(char *src, int size);
void		print_ascii(char *src, int size);
void		print_sh_content(void *data, Elf32_Shdr *shdr);
void		print_sh_name(t_info *info);

#endif /* !_MY_OBJDUMP_H_ */
