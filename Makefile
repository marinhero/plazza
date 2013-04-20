##
## Makefile for plazza in /home/hero/Dropbox/plazza
##
## Made by xiaoyan zhang
## Login   <zhang_x@epitech.net>
##
## Started on  Thu Apr 18 17:02:53 2013 xiaoyan zhang
## Last update Sat Apr 20 11:27:27 2013 Marin Alcaraz
##

SRC			= 		Exception.cpp 	\
			 	 	Reception.cpp 	\
			  		Graphics.cpp 	\
			  		Order.cpp 		\
			  		main.cpp

OBJ			= $(SRC:.cpp=.o)

CPPFLAGS	= -W -Wall -Werror -Wextra

CC			= g++

NAME		= the_plazza

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -lncurses $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
