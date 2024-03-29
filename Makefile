##
## Makefile for plazza in /home/hero/Dropbox/plazza
##
## Made by xiaoyan zhang
## Login   <zhang_x@epitech.net>
##
## Started on  Thu Apr 18 17:02:53 2013 xiaoyan zhang
## Last update Sun Apr 21 21:47:17 2013 Marin Alcaraz
##

SRC			= 		Exception.cpp 			\
			 	 	Reception.cpp 			\
			  		Graphics.cpp 			\
			  		Order.cpp 				\
			  		Pizza.cpp 				\
			  		PizzaFactory.cpp 		\
			  		Kitchen.cpp 			\
					Cook.cpp 				\
					KitchenPizzas.cpp 		\
					KitchenStock.cpp 		\
					Thread.cpp 				\
					ResourceLock.cpp 		\
			  		main.cpp

OBJ			= $(SRC:.cpp=.o)

CPPFLAGS	= -W -Wall -Werror -Wextra

CC			= g++

NAME		= plazza

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses -lpanel -lpthread

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
