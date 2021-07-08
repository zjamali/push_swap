
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
	sort_data.c\
	sort_five_numbers.c\
	sort_less_then_five_numbers.c\
	ft_sort_using_sequence.c\
	align_stacks.c\
	find_best_item.c\
	find_inc_sequence.c\
	parse_data.c\
	push_data_to_stack.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEDAERS = src/push_swap.h

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all: libft vectors $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEDAERS)
	@mkdir obj 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C src/libft

vectors: 
	make -C src/vector_lib

checker: libft vectors
	mkdir obj 2> /dev/null || true
	$(CC) $(CFLAGS) -c src/checker.c -o obj/checker.o
	$(CC) $(CFLAGS) -c src/parse_data.c -o obj/parse_data.o
	$(CC) $(CFLAGS) -c src/ft_check_data.c -o obj/ft_check_data.o
	$(CC) $(CFLAGS) -c src/ft_check_errors.c -o obj/ft_check_errors.o
	$(CC) $(CFLAGS) -c src/push_data_to_stack.c -o obj/push_data_to_stack.o
	$(CC) $(CFLAGS) -c src/gnl/get_next_line_utils.c -o obj/get_next_line_utils.o
	$(CC) $(CFLAGS) -c src/gnl/get_next_line.c -o obj/get_next_line.o
	$(CC) $(CFLAGS) -c src/instructions.c -o obj/instructions.o
	$(CC) $(CFLAGS) -c src/instructions_two_stacks.c -o obj/instructions_two_stacks.o
	$(CC) obj/parse_data.o obj/ft_check_data.o obj/ft_check_errors.o obj/checker.o\
	 obj/push_data_to_stack.o obj/get_next_line.o obj/get_next_line_utils.o \
	 obj/instructions.o  obj/instructions_two_stacks.o \
	 $(LIBFF_DIR)/libft.a $(VECTOR_DIR)/vectors.a -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf src/libft/*.o
	rm -rf src/vector_lib/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf src/libft/libft.a
	rm -rf src/vector_lib/vectors.a

re: fclean all