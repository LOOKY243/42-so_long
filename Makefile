CC=clang
NAME = so_long
SRCPATH = srcs/
SRCS = enemy.c \
		parsing.c \
		parsing2.c \
		main.c free.c \
		moves.c \
		counter.c \
		load_images.c \
		objects.c \
		place_images.c \
		ft_split.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c
HEADER = so_long.h
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADINC = $(addprefix $(SRCPATH), $(HEADER))
OBJS = $(SRCSINC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./$(SRCPATH) MLX42/build/libmlx42.a -Iinclude -pthread -ldl -lglfw -lX11 -lm -o $(NAME)

%.o : %.c $(HEADINC)
	$(CC) $(CFLAGS) -I./$(SRCPATH)  $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re