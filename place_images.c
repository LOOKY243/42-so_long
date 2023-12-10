/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:55 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/08 19:22:49 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_image(char **map, int y, int x, t_game *param)
{
	if (map[y][x] == FLOOR || map[y][x] == PLAYER || map[y][x] == COLLEC
			|| map[y][x] == EXIT)
		mlx_image_to_window(param->mlx, param->images->floor, x * 64, y * 64);
	if (map[y][x] == COLLEC)
	{
		mlx_image_to_window(param->mlx, param->images->coin, x * 64, y * 64);
		param->n_collect++;
	}
	if (map[y][x] == EXIT)
		mlx_image_to_window(param->mlx, param->images->exit, x * 64, y * 64);
	else if (map[y][x] == WALL)
		mlx_image_to_window(param->mlx, param->images->wall, x * 64, y * 64);
}

void	place_player(char **map, t_game *param)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				mlx_image_to_window(param->mlx, param->images->player,
					x * 64, y * 64);
				break ;
			}
			x++;
		}
	}
}

void	ft_place_map(char	**map, t_game *param)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			place_image(map, y, x, param);
			x++;
		}
	}
	place_player(param->map, param);
	mlx_image_to_window(param->mlx, param->images->player,
		param->images->player->instances[0].x * 64,
		param->images->player->instances[0].y * 64);
}
