##
## Makefile for 203hotline in /home/lin_c/Downloads/203hotline
## 
## Made by LIN Chaohui
## Login   <lin_c@epitech.net>
## 
## Started on  Sun Mar 29 14:09:39 2015 LIN Chaohui
## Last update Sun Mar 29 22:47:51 2015 Daniel Han
##

SOURCES =	hotline.cpp	\
		graph/create_graph.cpp	\
		graph/camera.cpp\
		graph/vector3d.cpp	\
		graph/objects.cpp	\
		main.cpp	\

OBJECTS	=	$(SOURCES:.cpp=.o)

TARGET	=	203hotline

LIBS	=	$(shell sdl-config --libs) -lSDL_image -lGL -lGLU

all:		$(OBJECTS)
		g++ $(LIBS) -o $(TARGET) $(OBJECTS)

clean:
		rm -rf $(OBJECTS)

fclean:		clean
		rm -rf $(TARGET)

re:		fclean all

