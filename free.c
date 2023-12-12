/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:00:11 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/12 17:00:12 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_images(t_game *param)
{
	mlx_delete_image(param->mlx, param->images->player);
	mlx_delete_image(param->mlx, param->images->floor);
	mlx_delete_image(param->mlx, param->images->middle);
	mlx_delete_image(param->mlx, param->images->bot);
	mlx_delete_image(param->mlx, param->images->bot_right);
	mlx_delete_image(param->mlx, param->images->top);
	mlx_delete_image(param->mlx, param->images->top_right);
	mlx_delete_image(param->mlx, param->images->left);
	mlx_delete_image(param->mlx, param->images->top_left);
	mlx_delete_image(param->mlx, param->images->right);
	mlx_delete_image(param->mlx, param->images->bot_left);
	mlx_delete_image(param->mlx, param->images->chest);
	mlx_delete_image(param->mlx, param->images->exit);
	free(param->images);
}

void	free_all(t_game *param)
{
    int i;

    i = 0;
	free_images(param);
	while (param->map[i])
	{
		free(param->map[i]);
		free(param->map2[i]);
		free(param->map3[i]);
		i++;
	}
	free(param->map);
	free(param->map2);
	free(param->map3);
}