##
## Makefile for  in /home/locque_d//rendu/proj/nm
##
## Made by damien locque
## Login   <locque_d@epitech.net>
##
## Started on  Mon Mar  7 18:19:44 2011 damien locque
## Last update Tue Mar 29 18:05:19 2011 damien locque
##

NAME_OBJ	= my_objdump
NAME_NM		= my_nm

OBJ_SRCS	= obj/objdump_main.c	\
		  obj/obj_header.c	\
		  obj/obj_print.c	\
		  obj/filesize.c

NM_SRCS		= nm/nm_main.c		\
		  nm/nm_print.c		\
		  nm/nm_list.c		\
		  nm/nm_symtype.c	\
		  obj/filesize.c

XSRCS		= xfunc/xopen.c		\
		  xfunc/xclose.c	\
		  xfunc/xmmap.c

OBJ_OBJS	= $(OBJ_SRCS:.c=.o)	\
		  $(XSRCS:.c=.o)

NM_OBJS		= $(NM_SRCS:.c=.o)	\
		  $(XSRCS:.c=.o)

CC		= gcc -g3
RM		= rm -f
MV		= mv

CFLAGS		+= -W -Wall -Wextra
INC		= -I ./include/

all		: my_objdump my_nm

$(NAME_OBJ)	: $(OBJ_OBJS)
		$(CC) -o $(NAME_OBJ) $(OBJ_OBJS) $(INC)
		$(MV) $(NAME_OBJ) ./bin/

$(NAME_NM)	: $(NM_OBJS)
		$(CC) -o $(NAME_NM) $(NM_OBJS) $(INC)
		$(MV) $(NAME_NM) ./bin/

.c.o		:
		$(CC) $(INC) -c $< -o $@

clean		:
		$(RM) $(OBJ_OBJS)
		$(RM) $(NM_OBJS)

fclean : clean
	$(RM) ./bin/$(NAME_OBJ)
	$(RM) ./bin/$(NAME_NM)

re	: fclean all
