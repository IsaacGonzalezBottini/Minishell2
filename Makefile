##
## EPITECH PROJECT, 2022
## makefile hunter
## File description:
## hunter
##

CC    =    gcc

SRC     =	lib/my_str_to_word_array.c \
			lib/my_strcat.c \
			lib/my_strlen.c \
			lib/my_str_isalpha.c \
			lib/my_str_isnum.c \
			lib/my_strcpy.c \qfd
			lib/separate_on_char.c \qdsfqfsd
			src/env.c \fqdfqd
			src/execute.c \
			src/builtin_command.c \
			src/redirection.c \
			src/redirection_left.c \
			src/pipe.c \
			src/cd_function.c \
			src/error.c \
			src/main.c

OBJ     =    $(SRC:.c=.o)

NAME    =    mysh

CPPFLAGS = -lncurses -Iinclude

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f *.o
	rm -f src/*.o
	rm -f lib/*.o

fclean:    clean
	rm -f $(NAME)

re:    clean all

debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) -g3
	valgrind ./$(NAME)



dqfs
