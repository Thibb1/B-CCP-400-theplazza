##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

NAME = 	plazza

SRC	= 	src/Main.cpp\
		src/Parse.cpp\
		src/Core.cpp\
		src/Kitchen.cpp\
		src/Shell.cpp\
		src/RegexUtils.cpp\
		src/Encapsulation/Mutex.cpp\
		src/Encapsulation/Thread.cpp\
		src/Encapsulation/Process.cpp

all: $(NAME)

CFLAGS = -W -Wextra -Wall -Werror -lpthread -Iincludes -Isrc/Encapsulation -std=c++20

$(NAME): $(OBJ)
		g++ $(CFLAGS) -g -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all