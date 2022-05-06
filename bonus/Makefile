##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

NAME = binary

SRC	= 	main.cpp\

all: $(NAME)

CFLAGS = -W -Wextra -Wall -Werror -lpthread -std=c++14

$(NAME): $(OBJ)
		g++ $(CFLAGS) -g -o $(NAME) $(SRC)

clean:

fclean: clean
		rm -f $(NAME)

re: fclean all