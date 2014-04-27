/*
** nm_symtype.c for  in /home/locque_d//rendu/proj/nm/nm
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sun Mar 13 20:56:21 2011 damien locque
** Last update Thu Mar 17 10:58:53 2011 damien locque
*/

#include <elf.h>
#include <stdlib.h>
#include "my_nm.h"

t_sym        gl_sym[6] =
  {
    {'D', SHT_PROGBITS, SHF_ALLOC + SHF_WRITE},
    {'D', SHT_DYNAMIC, SHF_ALLOC + SHF_WRITE},
    {'T', SHT_PROGBITS, SHF_ALLOC + SHF_EXECINSTR},
    {'B', SHT_NOBITS, SHF_ALLOC + SHF_WRITE},
    {'R', SHT_PROGBITS, SHF_ALLOC},
    {0, 0 , 0}
  };

static char	check_local(Elf32_Sym *sym, char c)
{
  return ((ELF32_ST_BIND(sym->st_info) == STB_LOCAL) ? (c + 32) : c);
}

char		get_type(t_list *chunk, Elf32_Shdr *shdr)
{
  int		i;
  char		res;

  i = 0;
  res = 'U';
  if (chunk->sym->st_shndx == SHN_ABS || chunk->sym->st_shndx == SHN_COMMON)
    return (check_local(chunk->sym, 'A'));
  if (ELF32_ST_BIND(chunk->sym->st_info) == STB_WEAK)
    {
      res = (ELF32_ST_TYPE(chunk->sym->st_info) == STT_OBJECT) ? 'V' : 'W';
      return ((chunk->sym->st_value) ? res : (res + 32));
    }
  while (gl_sym && gl_sym[i].symtype)
    {
      if (gl_sym[i].symattr == (&shdr[chunk->sym->st_shndx])->sh_type &&
	  gl_sym[i].symflag == (&shdr[chunk->sym->st_shndx])->sh_flags)
	res = gl_sym[i].symtype;
      i++;
    }
  return (check_local(chunk->sym, res));
  return res;
}
