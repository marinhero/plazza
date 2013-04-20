##
## Makefile for plazza in /home/hero/Dropbox/plazza
##
## Made by xiaoyan zhang
## Login   <zhang_x@epitech.net>
##
## Started on  Thu Apr 18 17:02:53 2013 xiaoyan zhang
## Last update Fri Apr 19 17:08:48 2013 Marin Alcaraz
##

SRC		= Exception.cpp \
		  Param.cpp 	\
		  ParamUnitTest.cpp

OBJ		= $(SRC:.cpp=.o)

CPPFLAGS	= -W -Wall -Werror -Wextra

CC		= g++

NAME		= plazza

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
