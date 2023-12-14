/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:13:58 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/14 12:17:14 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_possible2(char **map3)
{
	int	y;
	int	x;

	y = 0;
	while (map3[y])
	{
		x = 0;
		while (map3[y][x])
		{
			if (map3[y][x] == COLLEC || map3[y][x] == EXIT)
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	is_possible(t_game *param, int y, int x, int trigger)
{
	while (param->map[y] && trigger == 0)
	{
		x = -1;
		while (param->map[y][++x] && trigger == 0)
		{
			if (param->map[y][x] == 'P')
			{
				trigger = 1;
				y--;
				x--;
			}
		}
		y++;
	}
	param->map3[y][x] = WALL;
	if (param->map3[y][x + 1] && param->map3[y][x + 1] != WALL)
		is_possible(param, y, x + 1, 1);
	if (param->map3[y][x - 1] && param->map3[y][x - 1] != WALL)
		is_possible(param, y, x - 1, 1);
	if (param->map3[y + 1][x] && param->map3[y + 1][x] != WALL)
		is_possible(param, y + 1, x, 1);
	if (param->map3[y - 1][x] && param->map3[y - 1][x] != WALL)
		is_possible(param, y - 1, x, 1);
	return (is_possible2(param->map3));
}

int	check_walls(t_game *param)
{
	int	x;
	int	y;
	int	endwall;

	y = -1;
	endwall = ft_strlen(param->map[0]);
	while (param->map[++y])
	{
		if (y == 0 || y == find_sizey(param->map) / 64 - 1)
		{
			x = 0;
			while (param->map[y][x] && param->map[y][x] == WALL)
				x++;
			if (x != endwall)
				return (FALSE);
		}
		else if (param->map[y][0] != WALL || param->map[y][endwall - 1] != WALL)
			return (FALSE);
	}
	return (TRUE);
}

int	check_lenght(t_game *param)
{
	int	comp;
	int	y;

	comp = ft_strlen(param->map[0]);
	y = 0;
	while (param->map[y])
	{
		if (ft_strlen(param->map[y]) != comp)
		{
			puts("Error,\nIncorrect lenght of line");
			return (FALSE);
		}
		y++;
	}
	return (TRUE);
}

int	is_square(t_game *param)
{
	int	x;
	int	y;

	x = 0;
	while (param->map[0][x])
		x++;
	y = 0;
	while (param->map[y])
		y++;
	if (x == y)
	{
		puts("Error,\nMap can't be a square");
		return (FALSE);
	}
	return (TRUE);
}
