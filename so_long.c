/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:59:13 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/01 17:14:13 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "MLX42/include/MLX42/MLX42_Int.h"
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_img_move {
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img_move;

static mlx_image_t *image;

void ft_hook(void *param)
{
	mlx_t	*mlx = param;
	//mlx_t* mlx = param->mlx;
	//mlx_image_t *img = param->img;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

t_img_move	*put_in_struct(mlx_image_t *img, mlx_t *mlx)
{
	t_img_move	*index;

	index->img = img;
	index->mlx = mlx;
	return (index);
}

mlx_image_t	*ft_get_image(mlx_t *mlx, const char *image_file)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	img = mlx_new_image(mlx, 64, 64);
	texture = mlx_load_png(image_file);
	img = mlx_texture_to_image(mlx, texture);
	return (img);
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*bush;
	int				fd;
	int				i;
	char				*player_pos;
	int				posx;
	int				posy;
	char			*str;

	mlx = mlx_init(500, 500, "MLX42", true);
	if (!mlx)
		return (0);
	img = ft_get_image(mlx, "images/grass.png");
	bush = ft_get_image(mlx, "images/bush.png");
	image = ft_get_image(mlx, "images/front_stand.png");
	fd = open("maps/testmap.ber", O_RDONLY);
	str = get_next_line(fd);
	posx = 0;
	posy = 0;
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '0')
				mlx_image_to_window(mlx, img, posx, posy);
			else if (str[i] == '1')
				mlx_image_to_window(mlx, bush, posx, posy);
			else if (str[i] == 'P')
			{
				mlx_image_to_window(mlx, img, posx, posy);
				mlx_image_to_window(mlx, image, posx, posy);
			}
			posx += 64;
			i++;
		}
		posy += 64;
		posx = 0;
		str = get_next_line(fd);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	return (1);
}
