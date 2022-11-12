NAME = libasm.a
CC=gcc
FLAGS= -Wall -Werror -Wextra
SRC = ft_strlen.s
OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.s
	nasm -felf64 $<

test: $(NAME)
	$(CC) $(FLAGS) -I. main.c -L. -lasm -o ft_test

clean_test:
	/bin/rm -rf main.o

fclean_test:
	/bin/rm -rf ft_test

clean: clean_test
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re test
