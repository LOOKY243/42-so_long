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
	static int	i = 0;

	if (map[y][x] == FLOOR || map[y][x] == PLAYER || map[y][x] == COLLEC
			|| map[y][x] == EXIT)
		mlx_image_to_window(param->mlx, param->images->floor, x * 64, y * 64);
	if (map[y][x] == COLLEC)
	{
		mlx_image_to_window(param->mlx, param->images->chest, x * 64, y * 64);
		mlx_image_to_window(param->mlx, param->images->o_chest, x * 64, y * 64);
		param->images->o_chest->instances[i].enabled = false;
		param->n_collect++;
		i++;
	}
	if (map[y][x] == EXIT)
	{
		mlx_image_to_window(param->mlx, param->images->exit, x * 64, y * 64);
		mlx_image_to_window(param->mlx, param->images->o_exit, x * 64, y * 64);
		param->images->o_exit->instances[0].enabled = false;
	}
	else if (map[y][x] == WALL && x == 0)
		mlx_image_to_window(param->mlx, param->images->left, x * 64, y * 64);
	else if (map[y][x] == WALL && x == ft_strlen(map[y]) - 1)
		mlx_image_to_window(param->mlx, param->images->right, x * 64, y * 64);
	else if (map[y][x] == WALL && x != 0 && x != ft_strlen(map[y]) - 1)
		mlx_image_to_window(param->mlx, param->images->middle, x * 64, y * 64);
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
				mlx_image_to_window(param->mlx, param->images->p_front,
					x * 64, y * 64);
				mlx_image_to_window(param->mlx, param->images->p_back,
					x * 64, y * 64);
				mlx_image_to_window(param->mlx, param->images->p_left,
					x * 64, y * 64);
				mlx_image_to_window(param->mlx, param->images->p_right,
					x * 64, y * 64);
				break ;
			}
			x++;
		}
	}
}

void	place_top_walls(char **map, t_game *param)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (x == 0)
			mlx_image_to_window(param->mlx, param->images->top_left,
				x * 64, 0 * 64);
		else if (x == ft_strlen(map[0]) - 1)
			mlx_image_to_window(param->mlx, param->images->top_right,
				x * 64, 0 * 64);
		else
			mlx_image_to_window(param->mlx, param->images->top,
				x * 64, 0 * 64);
		x++;
	}
}

void	place_bot_walls(int y, char **map, t_game *param)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (x == 0)
			mlx_image_to_window(param->mlx, param->images->bot_left,
				x * 64, y * 64);
		else if (x == ft_strlen(map[y]) - 1)
			mlx_image_to_window(param->mlx, param->images->bot_right,
				x * 64, y * 64);
		else
			mlx_image_to_window(param->mlx, param->images->bot,
				x * 64, y * 64);
		x++;
	}
}

void	ft_place_map(char	**map, t_game *param)
{
	int	y;
	int	x;

	place_top_walls(param->map, param);
	y = 1;
	while (y < find_sizey(map) / 64 - 1)
	{
		x = 0;
		while (map[y][x])
		{
			place_image(map, y, x, param);
			x++;
		}
		y++;
	}
	place_bot_walls(y, param->map, param);
	param->is_enemy = spawn_enemy(param);
	place_player(param->map, param);
	param->images->p_back->instances[0].enabled = false;
	param->images->p_right->instances[0].enabled = false;
	param->images->p_left->instances[0].enabled = false;
	mlx_image_to_window(param->mlx, param->images->p_front,
		param->images->p_front->instances[0].x * 64,
		param->images->p_front->instances[0].y * 64);
}
