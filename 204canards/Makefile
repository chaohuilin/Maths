##
## Makefile for 204canards in /home/han_d/rendu/204canards
## 
## Made by Daniel Han
## Login   <han_d@epitech.net>
## 
## Started on  Sun Apr 12 21:17:54 2015 Daniel Han
## Last update Sun Apr 12 21:17:54 2015 Daniel Han
##

NAME		=	204canards

NAME_DIR	=	./sources/

SRC_NAME	=	$(NAME_DIR)main.c \
			$(NAME_DIR)initSDL.c \
			$(NAME_DIR)calc.c \
			$(NAME_DIR)display_cas.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

INCLUDE		=	./includes/

CFLAGS		=	-I$(INCLUDE) -lSDL -lSDL_ttf -lSDL_gfx -lm

GCC		=	gcc

RM		=	rm -rf

ECHO		=	echo -e

all		:	$(NAME)

$(NAME)	:		$(OBJ_NAME)
			$(GCC) $(CFLAGS) -o $(NAME) $(OBJ_NAME)
			@$(ECHO) '\033[0;36m> Binary Compiled\033[0m'

clean		:
			$(RM) *~ *# *.
			$(RM) $(INCLUDE)*~ $(INCLUDE)*# $(INCLUDE)*.
			$(RM) $(NAME_DIR)*~ $(NAME_DIR)*# $(NAME_DIR)*.
			$(RM) $(OBJ_NAME)
			@$(ECHO) '\033[0;36m> Directory Cleaned\033[0m'

fclean		:	clean
			$(RM) $(NAME)
			@$(ECHO) '\033[0;36m> Executable Removed\033[0m'

re		:	fclean all

.PHONY		:	all clean fclean re
