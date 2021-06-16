NAME= vectors.a

SRC= vectors.c vectors_utils.c


LIB= vectors.h
OBJ= $(SRC:.c=.o)
CFLAGS=  -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean 
	@rm -f $(NAME)
re: fclean all
