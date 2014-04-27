/*
** obj_header.c for  in /home/locque_d//rendu/proj/nm/obj
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Fri Mar  4 17:59:10 2011 damien locque
** Last update Mon Mar  7 17:48:07 2011 damien locque
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_objdump.h"

char *machine_name[6] = {
  "Not Recognize",
  "AT&T WE 32100",
  "SUN SPARC",
  "i386",
  "Motorola m68k family",
  "Motorola m88k family"
};
// flemme de faire les 95++

void		print_header(t_info *info, char *pathname)
{
  printf("\n");
  printf("%s:\tfile format elf32-%s\n", pathname,
	 (info->elf->e_machine <= 6 ?
	  machine_name[info->elf->e_machine] : "unknown"));
  printf("architecture: %s, flags \n",
	 (info->elf->e_machine <= 6 ?
	  machine_name[info->elf->e_machine] : "unknown"));
  printf("start address 0x%08x\n", info->elf->e_entry);
  printf("\n");
}

