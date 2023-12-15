/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:37:05 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/15 12:26:10 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static unsigned int	g_custom_seed = 5;

unsigned int	custom_rand(void)
{
	const unsigned int	a = 1664525;
	const unsigned int	c = 1013904223;

	g_custom_seed = a * g_custom_seed + c;
	return (g_custom_seed);
}

int	random_num(int min, int max)
{
	int	temp;
	int	range;
	int	random_number;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	range = max - min + 1;
	random_number = custom_rand() % range + min;
	g_custom_seed = custom_rand() + min;
	return (random_number);
}

void	lose_to_enemy(t_game *param)
{
	if (param->is_enemy)
	{
		if (param->images->enemy->instances[0].y
			== param->images->p_front->instances[0].y
			&& param->images->enemy->instances[0].x
			== param->images->p_front->instances[0].x)
		{
			puts("You died to the enemy, better luck next time!");
			mlx_close_window(param->mlx);
		}
	}
}

void	move_enemy(t_game *param)
{
	int	num;

	num = random_num(1, 10);
	if (param->images->enemy)
	{
		lose_to_enemy(param);
		if (num == 1 || num == 5 || num == 7)
			if (param->map[param->images->enemy->instances[0].y / 64
					- 1][param->images->enemy->instances[0].x / 64] == FLOOR)
				param->images->enemy->instances[0].y -= 64;
		if (num == 2 || num == 10)
			if (param->map[param->images->enemy->instances[0].y / 64]
				[param->images->enemy->instances[0].x / 64 + 1] == FLOOR)
				param->images->enemy->instances[0].x += 64;
		if (num == 3 || num == 9 || num == 8)
			if (param->map[param->images->enemy->instances[0].y / 64
					+ 1][param->images->enemy->instances[0].x / 64] == FLOOR)
				param->images->enemy->instances[0].y += 64;
		if (num == 4 || num == 6)
			if (param->map[param->images->enemy->instances[0].y / 64]
				[param->images->enemy->instances[0].x / 64 - 1] == FLOOR)
				param->images->enemy->instances[0].x -= 64;
		lose_to_enemy(param);
	}
}

int	spawn_enemy(t_game *param)
{
	int	x;
	int	y;

	if (find_sizey(param->map) / 64 <= 3)
		return (FALSE);
	param->images->enemy = ft_get_image(param->mlx, "textures/enemy.png");
	y = 0;
	while (param->map[y])
	{
		x = random_num(1, 10);
		if (param->map[y][x] == FLOOR)
		{
			mlx_image_to_window(param->mlx, param->images->enemy, x * 64, y
				* 64);
			return (TRUE);
		}
		y++;
	}
	return (FALSE);
}
