CC=clang
NAME = so_long
INCPATH = includes/
SRCPATH = srcs/
SRCS = enemy.c parsing.c parsing2.c main.c free.c moves.c counter.c load_images.c objects.c place_images.c ft_split.c
HEADER = so_long.h
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADINC = $(addprefix $(INCPATH), $(HEADER))
OBJS = $(SRCSINC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all:$(NAME)

$(NAME): $(OBJS)
    @make --no-print-directory -C mlx
    cp mlx/libmlx_Linux.a ./$(INCPATH)
    @make bonus -j 40 --no-print-directory -C libft
    cp libft/libft.a ./$(INCPATH)
    $(CC) $(OBJS) -L./$(INCPATH) -lft -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEADINC)
    $(CC) $(CFLAGS) -I./$(INCPATH)  $< -c -o $@

fclean: clean
    rm -f $(NAME)
    rm -f ./$(INCPATH)libft.a
    rm -f ./$(INCPATH)libmlx_Linux.a
    @make fclean --no-print-directory -C libft

clean:
    @rm -f $(OBJS)
    @make clean --no-print-directory -C libft
    @make clean --no-print-directory -C mlx

re: fclean all

.PHONY: all fclean clean re