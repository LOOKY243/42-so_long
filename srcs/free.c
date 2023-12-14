/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:00:11 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/12 18:26:36 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_all(t_game *param)
{
	int	i;

	i = 0;
	free(param->images);
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
