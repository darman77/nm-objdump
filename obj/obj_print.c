/*
** obj_print.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 18:02:57 2011 damien locque
** Last update Sun Mar 13 20:22:33 2011 damien locque
*/

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_objdump.h"
#include "xfunc.h"

void		print_address(unsigned int end_section, unsigned int addr)
{
  char		buf[16];
  int		rd;

  rd = sprintf(buf, "%x", end_section);
  rd = (rd < 4) ? 4 : rd;
  printf(" %0*x ", rd, addr);
}

void		print_hexa(char *src, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      printf("%02x", ((unsigned char)src[i]));
      if ((i + 1) % 4 == 0)
	printf(" ");
      i++;
    }
  while (i != 16)
    {
      printf("  ");
      if ((i + 1) % 4 == 0)
	printf(" ");
      i++;
    }
  printf(" ");
  print_ascii(src, size);
}

void		print_ascii(char *src, int size)
{
  int		i;
  char		res[17];

  i = 0;
  memset(res, 32, 16);
  res[16] = '\0';
  while (i < size)
    {
      if (src[i] >= 32 && src[i] <= 126)
	res[i] = src[i];
      else
	res[i] = '.';
      i++;
    }
  printf("%s\n", res);
}

void		print_sh_content(void *data, Elf32_Shdr *shdr)
{
  unsigned int	i;
  int		j;
  char		buf[17];

  i = 0;
  j = 0;
  while (i < shdr->sh_size)
    {
      buf[j++] = *(((char *)(data)) + shdr->sh_offset + i);
      if (j == 16)
	{
	  print_address(((unsigned int)((char *)shdr->sh_addr + shdr->sh_size)),
			(unsigned int)((char *)shdr->sh_addr + i - j + 1));
	  print_hexa(buf, 16);
	  memset(buf, '\0', 17);
	  j = 0;
	}
      i++;
    }
  if (j > 0)
    {
      print_address(((unsigned int)((char *)shdr->sh_addr + shdr->sh_size)),
		    (unsigned int)((char *)shdr->sh_addr + i - j));
      print_hexa(buf, j);
    }
}

void		print_sh_name(t_info *info)
{
  int		i;

  i = 0;
  while (i < info->elf->e_shnum)
    {
      if (info->shdr[i].sh_type != SHT_NOBITS &&
	  info->shdr[i].sh_type != SHT_SYMTAB &&
	  info->shdr[i].sh_type != SHT_NULL &&
	  (info->shdr[i].sh_type != SHT_STRTAB ||
	   info->shdr[i].sh_flags & SHF_ALLOC))
	{
	  printf("Contents of section %s:\n",
		 &info->strtab[info->shdr[i].sh_name]);
	  print_sh_content(info->data, &info->shdr[i]);
	}
      i++;
    }
}
