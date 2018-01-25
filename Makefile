##
## Makefile for my_exec in /root/Delivery/CProg_Elem/CPE_2016_BSQ
## 
## Made by root
## Login   <kentin.pratelli@epitech.eu>
## 
## Started on  Tue May  2 13:21:14 2017 root
## Last update Mon Oct  2 00:37:52 2017 root
##

CC      =       gcc

RM	=	rm -f

CFLAGS  +=	-Wextra -Wall -W -I ./include/

NAME_G	=	generator

SRCS_G	=	./src/create_tab.c		\
		./src/create_maze.c		\
		./src/backtrack.c		\
		./src/break_walls.c		\
		./src/list.c			\
		./src/verifs/arg.c		\
		./src/utils/my_strings.c	\
		./src/utils/intlen.c		\
		./src/main.c

OBJS_G	=	$(SRCS_G:.c=.o)


all:		$(NAME_G)

$(NAME_G):	$(OBJS_G)
		$(CC) -o $(NAME_G) $(OBJS_G)

clean:
		$(RM) $(OBJS_G)

fclean:		clean
		$(RM) $(NAME_G)

re:		fclean all

.PHONY:		all clean fclean re
