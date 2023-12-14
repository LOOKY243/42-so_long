/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:15:42 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/14 17:47:12 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define TRUE 1
# define FALSE 0
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLEC 'C'
# define PLAYER 'P'

typedef struct s_images
{
	mlx_image_t		*p_front;
	mlx_image_t		*p_back;
	mlx_image_t		*p_left;
	mlx_image_t		*p_right;
	mlx_image_t		*floor;
	mlx_image_t		*middle;
	mlx_image_t		*bot;
	mlx_image_t		*bot_right;
	mlx_image_t		*top;
	mlx_image_t		*top_right;
	mlx_image_t		*left;
	mlx_image_t		*top_left;
	mlx_image_t		*right;
	mlx_image_t		*bot_left;
	mlx_image_t		*chest;
	mlx_image_t		*o_chest;
	mlx_image_t		*exit;
	mlx_image_t		*o_exit;
	mlx_image_t		*num[10];
	mlx_image_t		*enemy;
}					t_images;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_key_data_t	keydata;
	t_images		*images;
	int				move_count;
	int				collect_count;
	int				n_collect;
	int				is_enemy;
	char			**map;
	char			**map2;
	char			**map3;
}					t_game;

int					ft_printf(const char *format, ...);
int					ft_putchar(int c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putunsigned(unsigned int n);
int					ft_base_sixteen(char arg, unsigned int n);
int					ft_which_printf(char format, va_list args);
int					ft_void_sixteen(unsigned long nb);
void				ft_load_images(t_game *param);
void				ft_keys(mlx_key_data_t keydata, t_game *param);
char				*ft_strjoin(char const *extra, char const *buff);
int					ft_strlen(char const *str);
int					find_sizey(char **str);
int					find_sizex(char **str);
int					ft_parsing(t_game *param);
char				*ft_strchr(char *s, int c);
char				*get_next_line(int fd);
unsigned int		ft_countsplit(const char *s, char c);
char				*ft_prealloc(char const *s, char c, int i);
char				**ft_split(const char *s, char c);
void				*ft_calloc(size_t nmemb, size_t size);
void				is_exit(t_game *param, int x, int y);
void				is_chest(t_game *param, int x, int y);
void				remove_chest(t_game *param);
void				ft_place_map(char **map, t_game *param);
void				free_all(t_game *param);
void				load_numbers(t_game *param);
mlx_image_t			*ft_get_image(mlx_t *mlx, const char *image_file);
void				counter(t_game *param);
int					is_square(t_game *param);
int					check_walls(t_game *param);
int					is_possible(t_game *param, int y, int x, int trigger);
int					check_lenght(t_game *param);
mlx_image_t			*ft_get_image(mlx_t *mlx, const char *image_file);
int	    			spawn_enemy(t_game *param);
void    			move_enemy(t_game *param);

#endif
