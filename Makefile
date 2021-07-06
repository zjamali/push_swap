
NAME = push_swap
SRC_DIR = ./src
OBJ_DIR = ./obj

LIBFF_DIR = ./src/libft
VECTOR_DIR = ./src/vector_lib

CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRC_NAME = main.c\
	ft_check_data.c\
	ft_check_errors.c\
	push_swap.c\
	instructions.c\
	instructions_two_stacks.c\
	find_median.c\
	sort_data.c\
	sort_five_numbers.c\
	sort_less_then_five_numbers.c\
	ft_sort_using_sequence.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEDAERS = src/push_swap.h

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: libft vectors $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEDAERS)
	@echo $@
	@mkdir obj 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C src/libft

vectors: 
	make -C src/vector_lib
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf src/libft/*.o
	rm -rf src/vector_lib/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf src/libft/libft.a
	rm -rf src/vector_lib/vectors.a

re: fclean all