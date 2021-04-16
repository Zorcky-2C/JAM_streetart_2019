##
## EPITECH PROJECT, 2020
## JAM_streetart_2019
## File description:
## Makefile
##

.PHONY			: 	all clean fclean re

NAME			=	streetart

SRC 			=	src/main.cpp \
					src/menu.cpp \
					src/lineshape.cpp \
					src/game.cpp \
					src/utils.cpp

OBJ				= 	$(SRC:.cpp=.o)

CC				= 	g++

CFLAGS 			+=  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -Wextra #-Werror

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean			:
					rm -f $(OBJ)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all