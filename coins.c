/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:50:11 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/08 19:22:26 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	which_instance(char **map2, t_game *param)
{
	int	y;
	int	x;
	int	count;

	y = -1;
	count = -1;
	while (map2[++y])
	{
		x = 0;
		while (map2[y][x])
		{
			if (map2[y][x] == 'C')
				count++;
			if (param->images->player->instances[0].y / 64 == y
				&& param->images->player->instances[0].x / 64 == x)
				return (count);
			x++;
		}
	}
	return (count);
}

void	remove_coin(t_game *param)
{
	int	i;
	int	pos;

	i = param->n_collect;
	pos = which_instance(param->map2, param);
	while (i >= 0)
	{
		if (param->images->coin->instances[pos].y
			== param->images->player->instances[0].y
			&& param->images->coin->instances[pos].x
			&& param->images->player->instances[0].x
			&& param->images->coin->instances[pos].enabled)
		{
			param->images->coin->instances[pos].enabled = false;
			return ;
		}
		i--;
	}
}

void	is_coin(t_game *param, int x, int y)
{
	if (param->map[y][x] == 'C')
	{
		param->collect_count = param->collect_count + 1;
		param->map[param->images->player->instances[0].y / 64]
		[param->images->player->instances[0].x / 64] = FLOOR;
		remove_coin(param);
	}
}

void	is_exit(t_game *param, int x, int y)
{
	if (param->map[y][x] == 'E' && param->collect_count == param->n_collect)
		mlx_close_window(param->mlx);
}
