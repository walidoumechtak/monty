CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c89 -fsanitize=address -g3
NAME= monty

SRC = main.c readFile.c putError.c _strdup.c _strjoin.c _split.c fd_putstr.c free_split.c\
      free_list.c runByteCode.c free_ressource.c push.c pall.c len_list.c pint.c pop.c swap.c add.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)

all: $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
