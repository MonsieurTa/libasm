NAME = libasm.a
TEST_NAME = ft_test
CC=gcc
FLAGS= -Wall -Werror -Wextra
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s
OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.s
	nasm -felf64 $<

test: $(NAME)
	$(CC) $(FLAGS) -I. ./tests/main.c -L. -lasm -o $(TEST_NAME)
	./ft_test

clean_test:
	/bin/rm -rf main.o

fclean_test:
	/bin/rm -rf $(TEST_NAME)

clean: clean_test
	/bin/rm -rf $(OBJ)

fclean: clean fclean_test
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re test
