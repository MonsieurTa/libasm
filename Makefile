NAME = libasm.a
TEST_NAME = ft_test
CC=gcc
FLAGS= -Wall -Werror -Wextra
SRC = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s \
ft_atoi_base.s

TEST_SRC = tests/main.c \
tests/test_base.c \
tests/test_strlen.c \
tests/test_strcpy.c \
tests/test_strcmp.c \
tests/test_write.c \
tests/test_read.c \
tests/test_strdup.c \
tests/test_atoi_base.c

OBJ = $(SRC:.s=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.s
	nasm -felf64 $<

tests/%.o: tests/%.c
	$(CC) $(FLAGS) -I. -I./tests -c -o $@ $<

test: $(NAME) $(TEST_OBJ)
	$(CC) $(FLAGS) -o $(TEST_NAME) $(TEST_OBJ) $(NAME)
	./$(TEST_NAME)

clean_test:
	/bin/rm -rf $(TEST_OBJ)

fclean_test:
	/bin/rm -rf $(TEST_NAME)

clean: clean_test
	/bin/rm -rf $(OBJ)

fclean: clean fclean_test
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	clean fclean re test
