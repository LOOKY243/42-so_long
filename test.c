/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:46:45 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/01 12:58:16 by gmarre           ###   ########.fr       */
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

void ft_hook(t_img_move *param)
{
	mlx_t* mlx = param->mlx;
	mlx_image_t *img = param->img;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
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
	t_img_move		*mix;

	mlx = mlx_init(500, 500, "test", true);
	
	img = ft_get_image(mlx, "images/front_stand.png");
	mlx_image_to_window(mlx, img, 0, 0);

	mix = put_in_struct(img, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
}
