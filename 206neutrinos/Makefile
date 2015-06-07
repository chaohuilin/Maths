##
## Makefile for 206neutrinos in /home/han_d/rendu/206neutrinos
## 
## Made by Daniel Han
## Login   <han_d@epitech.net>
## 
## Started on  Mon May  4 03:50:03 2015 Daniel Han
## Last update Wed May  6 19:11:37 2015 Daniel Han
##

SRC	=	calculate.c \
		check_arg.c \
		display_error.c \
		display_result.c \
		parser.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	206neutrinos

COMP	=	gcc

RM	=	rm -f

ECHO	=	echo -e

CFLAGS  +=	-Wall -Werror -Wextra

LDFLAGS	+=	-lm

GREEN	=	"\033[0;32m"

RESET	=	"\033[0;m"

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(ECHO) $(GREEN) '-> Objects compiled'$(RESET)
		$(COMP) $(OBJ) $(LPATH) $(LDFLAGS) -o $(NAME)
		@$(ECHO) $(GREEN) '-> Executable compiled'$(RESET)

clean:
		$(RM) $(OBJ)
		@$(ECHO) $(GREEN) '-> Objects removed'$(RESET)

fclean:		clean
		$(RM) $(NAME)
		@$(ECHO) $(GREEN) '-> Executable removed'$(RESET)

re:		fclean all

.PHONY:		all clean fclean re
