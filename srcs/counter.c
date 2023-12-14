/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:51:51 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/13 15:13:02 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	load_numbers(t_game *param)
{
	param->images->num[1] = ft_get_image(param->mlx,
			"textures/numbers/one.png");
	param->images->num[2] = ft_get_image(param->mlx,
			"textures/numbers/two.png");
	param->images->num[3] = ft_get_image(param->mlx,
			"textures/numbers/three.png");
	param->images->num[4] = ft_get_image(param->mlx,
			"textures/numbers/four.png");
	param->images->num[5] = ft_get_image(param->mlx,
			"textures/numbers/five.png");
	param->images->num[6] = ft_get_image(param->mlx,
			"textures/numbers/six.png");
	param->images->num[7] = ft_get_image(param->mlx,
			"textures/numbers/seven.png");
	param->images->num[8] = ft_get_image(param->mlx,
			"textures/numbers/eight.png");
	param->images->num[9] = ft_get_image(param->mlx,
			"textures/numbers/nine.png");
	param->images->num[0] = ft_get_image(param->mlx,
			"textures/numbers/zero.png");
}

int	ft_getlen(int n)
{
	int	power;

	if (n <= 0)
		power = 1;
	else
		power = 0;
	while (n != 0)
	{
		power++;
		n /= 10;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	unsigned int	nb;
	char			*to_char;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	nb = n * sign;
	len = ft_getlen(n);
	to_char = (char *)ft_calloc(len + 1, sizeof(char));
	if (!to_char)
		return (NULL);
	to_char[len--] = '\0';
	while (len >= 0)
	{
		to_char[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign < 0)
		to_char[0] = '-';
	return (to_char);
}

void	counter(t_game *param)
{
	int		i;
	char	*n;

	i = 0;
	n = ft_itoa(param->move_count);
	while (n[i])
	{
		mlx_image_to_window(param->mlx, param->images->num[n[i] - '0'], i * 32
			+ 42, 9);
		i++;
	}
	free(n);
}
