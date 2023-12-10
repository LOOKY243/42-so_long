CC = clang
NAME = so_long.a
SRC = ft_split.c \
	  ft_calloc.c \
	  so_long.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c
HEADER = so_long.h
OBJ = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall -g

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ)

re : fclean all

bonus : all

.PHONY: all fclean clean re bonus
