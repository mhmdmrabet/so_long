SRC = so_long.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Werror -Wall

NAME = so_long.a

CC = gcc

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re