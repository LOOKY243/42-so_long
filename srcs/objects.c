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
			if (param->images->p_front->instances[0].y / 64 == y
				&& param->images->p_front->instances[0].x / 64 == x)
				return (count);
			x++;
		}
	}
	return (count);
}

void	remove_chest(t_game *param)
{
	int	i;
	int	pos;

	i = param->n_collect;
	pos = which_instance(param->map2, param);
	while (i >= 0)
	{
		if (param->images->chest->instances[pos].y
			== param->images->p_front->instances[0].y
			&& param->images->chest->instances[pos].x
			&& param->images->p_front->instances[0].x
			&& param->images->chest->instances[pos].enabled)
		{
			param->images->chest->instances[pos].enabled = false;
			param->images->o_chest->instances[pos].enabled = true;
			return ;
		}
		i--;
	}
}

void	is_chest(t_game *param, int x, int y)
{
	if (param->map[y][x] == 'C')
	{
		param->collect_count = param->collect_count + 1;
		param->map[param->images->p_front->instances[0].y / 64]
		[param->images->p_front->instances[0].x / 64] = FLOOR;
		remove_chest(param);
	}
}

void	is_exit(t_game *param, int x, int y)
{
	if (param->collect_count == param->n_collect)
	{
		param->images->exit->instances[0].enabled = false;
		param->images->o_exit->instances[0].enabled = true;
	}
	if (param->map[y][x] == 'E' && param->collect_count == param->n_collect)
		mlx_close_window(param->mlx);
	if (param->is_enemy)
	{
		if (param->images->enemy->instances[0].y
			== param->images->p_front->instances[0].y
			&& param->images->enemy->instances[0].x
			== param->images->p_front->instances[0].x)
			mlx_close_window(param->mlx);
	}
}
