##
## Makefile for 205QI in /home/han_d/rendu/205QI
## 
## Made by Daniel Han
## Login   <han_d@epitech.net>
## 
## Started on  Mon Apr 13 15:32:14 2015 Daniel Han
## Last update Mon Apr 13 16:51:26 2015 Daniel Han
##

SRC	=	main.c \
		axes.c \
		result.c

OBJ	=	$(SRC:.c=.o)

NAME	=	205QI

COMP	=	gcc

RM	=	rm -f

ECHO	=	echo -e

OPTI	= -O2

IPATH   = -I./include -I./src/proc
OBJOPT  = $(OPTI) #-W -Wall
CFLAGS  = $(OBJOPT) $(IPATH)
CXXFLAGS= $(CFLAGS)

LPATH   = -L. -lm `sdl-config --cflags --libs` -lSDL_gfx

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
