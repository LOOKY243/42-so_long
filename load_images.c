/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:19:29 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/06 17:43:23 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

mlx_image_t	*ft_get_image(mlx_t *mlx, const char *image_file)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	img = mlx_new_image(mlx, 64, 64);
	texture = mlx_load_png(image_file);
	img = mlx_texture_to_image(mlx, texture);
	return (img);
}

void	ft_load_images(t_game *param)
{
	param->images = ft_calloc(1, sizeof(t_images));
	param->images->floor = ft_get_image(param->mlx, "images/floor.png");
	param->images->wall = ft_get_image(param->mlx, "images/bush.png");
	param->images->player = ft_get_image(param->mlx, "images/front_stand.png");
	param->images->coin = ft_get_image(param->mlx, "images/coin.png");
	param->images->exit = ft_get_image(param->mlx, "images/exit.png");
}
