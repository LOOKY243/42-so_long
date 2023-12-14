/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:59 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/07 16:03:37 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *param)
{
	if (param->map[param->images->p_front->instances[0].y / 64 - 1]
		[param->images->p_front->instances[0].x / 64] != WALL)
	{
		param->images->p_front->instances[0].y -= 64;
		param->images->p_back->instances[0].y -= 64;
		param->images->p_left->instances[0].y -= 64;
		param->images->p_right->instances[0].y -= 64;
		param->images->p_front->instances[0].enabled = false;
		param->images->p_back->instances[0].enabled = true;
		param->images->p_left->instances[0].enabled = false;
		param->images->p_right->instances[0].enabled = false;
		param->move_count++;
		if (param->is_enemy)
			move_enemy(param);
		counter(param);
	}
}

void	ft_move_down(t_game *param)
{
	if (param->map[param->images->p_front->instances[0].y / 64 + 1]
		[param->images->p_front->instances[0].x / 64] != WALL)
	{
		param->images->p_front->instances[0].y += 64;
		param->images->p_back->instances[0].y += 64;
		param->images->p_left->instances[0].y += 64;
		param->images->p_right->instances[0].y += 64;
		param->images->p_front->instances[0].enabled = true;
		param->images->p_back->instances[0].enabled = false;
		param->images->p_left->instances[0].enabled = false;
		param->images->p_right->instances[0].enabled = false;
		param->move_count++;
		if (param->is_enemy)
			move_enemy(param);
		counter(param);
	}
}

void	ft_move_left(t_game *param)
{
	if (param->map[param->images->p_front->instances[0].y / 64]
		[param->images->p_front->instances[0].x / 64 - 1] != WALL)
	{
		param->images->p_front->instances[0].x -= 64;
		param->images->p_back->instances[0].x -= 64;
		param->images->p_left->instances[0].x -= 64;
		param->images->p_right->instances[0].x -= 64;
		param->images->p_front->instances[0].enabled = false;
		param->images->p_back->instances[0].enabled = false;
		param->images->p_left->instances[0].enabled = true;
		param->images->p_right->instances[0].enabled = false;
		param->move_count++;
		if (param->is_enemy)
			move_enemy(param);
		counter(param);
	}
}

void	ft_move_right(t_game *param)
{
	if (param->map[param->images->p_front->instances[0].y / 64]
		[param->images->p_front->instances[0].x / 64 + 1] != WALL)
	{
		param->images->p_front->instances[0].x += 64;
		param->images->p_back->instances[0].x += 64;
		param->images->p_left->instances[0].x += 64;
		param->images->p_right->instances[0].x += 64;
		param->images->p_front->instances[0].enabled = false;
		param->images->p_back->instances[0].enabled = false;
		param->images->p_left->instances[0].enabled = false;
		param->images->p_right->instances[0].enabled = true;
		param->move_count++;
		if (param->is_enemy)
			move_enemy(param);
		counter(param);
	}
}

void	ft_keys(mlx_key_data_t keydata, t_game *param)
{
	mlx_t	*mlx;

	mlx = param->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if ((keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		ft_move_up(param);
	if ((keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		ft_move_down(param);
	if ((keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		ft_move_left(param);
	if ((keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		ft_move_right(param);
	is_chest(param, param->images->p_front->instances[0].x / 64,
		param->images->p_front->instances[0].y / 64);
	is_exit(param, param->images->p_front->instances[0].x / 64,
		param->images->p_front->instances[0].y / 64);
}
