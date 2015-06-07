NAME 	= 208chevillettes

SRCS	= main.cpp	\
	  tab.cpp	\
	  fonctions.cpp\
	  printResult.cpp\
	  checkValues.cpp\
	  checkTabCase.cpp\

LPATH   = -L. -lm -lgmpxx -lgmp -I/usr/local/Cellar/gmp/

RM = /bin/rm -f

CC = g++

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(LPATH) -o $(NAME)

clean:
		$(RM) *.o

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
