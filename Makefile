
NAME = push_swap
SRC_DIR = ./src
OBJ_DIR = ./obj

LIBFF_DIR = ./src/libft
VECTOR_DIR = ./src/vector_lib

CFLAGS = -Wall -Werror -Wextra
CC = gcc

SRC_NAME = main.c\
	ft_check_errors.c\
	push_swap.c\
	instructions.c\
	instructions_two_stacks.c\
	find_median.c\
	ft_check_circular_sorted.c\
	sort_data.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEDAERS = src/push_swap.h

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) libft vectors
	$(CC) $(OBJ) $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEDAERS)
	@echo $@
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -sC src/libft

vectors: 
	make -sC src/vector_lib
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf src/libft/*.o
	rm -rf src/vector_lib/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf src/libft/libft.a
	rm -rf src/vector_lib/vectors.a