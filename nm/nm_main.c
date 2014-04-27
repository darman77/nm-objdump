/*
** main.c for  in /home/locque_d//rendu/proj/nm
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Wed Mar  2 11:44:36 2011 damien locque
** Last update Sun Mar 13 20:34:01 2011 damien locque
*/

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "xfunc.h"
#include "my_nm.h"

static int	check_file(t_info *info, char *path)
{
  if (info->elf->e_ident[0] != ELFMAG0 || info->elf->e_ident[1] != ELFMAG1
      || info->elf->e_ident[2] != ELFMAG2 || info->elf->e_ident[3] != ELFMAG3)
    {
      fprintf(stderr, "%s : Not Elf format\n", path);
      return (-1);
    }
}

static int	nm_a_out()
{
  int		fd;
  t_info	info;

  if ((fd = xopen("a.out", O_RDONLY)) == -1)
    return (EXIT_FAILURE);
  if ((info.data = xmmap(fd, "a.out")) == (void *)-1)
    return (EXIT_FAILURE);
  info.elf = (Elf32_Ehdr*)info.data;
  if (check_file(&info, "a.out") == -1)
    return (EXIT_FAILURE);
  info.shdr = (Elf32_Shdr*)((char *)info.data + info.elf->e_shoff);
  print_nm(&info);
  xclose(fd);
}

int		main(int argc, char **argv)
{
  int		i;
  int		fd;
  t_info	info;

  i = 0;
  if (argc == 1)
    return (nm_a_out());
  while (argc >= 2 && i < argc - 1)
    {
      i++;
      if ((fd = xopen(argv[i], O_RDONLY)) == -1)
	continue;
      if ((info.data = xmmap(fd, argv[i])) == (void *)-1)
	  continue;
      info.elf = (Elf32_Ehdr*)info.data;
      if (check_file(&info, argv[i]) == -1)
	continue;
      info.shdr = (Elf32_Shdr*)((char *)info.data + info.elf->e_shoff);
      print_nm(&info);
      xclose(fd);
    }
  return (EXIT_SUCCESS);
}

