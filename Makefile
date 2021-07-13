NAME = push_swap
CHECKER = checker
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
	sort_data.c\
	sort_five_numbers.c\
	sort_less_then_five_numbers.c\
	ft_sort_using_sequence.c\
	align_stacks.c\
	find_best_item.c\
	find_inc_sequence.c\
	parse_data.c\
	push_data_to_stack.c

CHECKER_SRC = checker.c\
	parse_data.c\
	ft_check_data.c\
	ft_check_errors.c\
	push_data_to_stack.c\
	get_next_line.c\
	instructions.c\
	instructions_two_stacks.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
HEDAERS = src/push_swap.h
CHECKER_HEADER =  src/checker.h
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
OBJ1 = $(addprefix $(OBJ_DIR)/,$(CHECKER_OBJ)) 
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
all: $(NAME)

$(NAME): $(OBJ)
	make -C src/libft
	make -C src/vector_lib
	$(CC) $(OBJ) $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEDAERS)
	@mkdir obj 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(CHECKER)

$(CHECKER): $(OBJ1)
	make -C src/libft
	make -C src/vector_lib 
	$(CC) $(OBJ1) $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf src/libft/*.o
	rm -rf src/vector_lib/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf src/libft/libft.a
	rm -rf src/vector_lib/vectors.a
	rm -rf checker

re: fclean all