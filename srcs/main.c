/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:56:10 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/08 19:22:00 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_sizex(char	**str)
{
	int	i;

	i = 0;
	while (str[0][i])
		i++;
	return (i * 64);
}

int	find_sizey(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i * 64);
}

void	gnl_to_split(t_game *param, int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	param->map = ft_split(tmp, '\n');
	free(tmp);
	tmp = get_next_line(fd);
	param->map2 = ft_split(tmp, '\n');
	free(tmp);
	tmp = get_next_line(fd);
	param->map3 = ft_split(tmp, '\n');
	free(tmp);
}

int	game(int fd)
{
	t_game		param;

	param.move_count = 0;
	param.collect_count = 0;
	param.n_collect = 0;
	gnl_to_split(&param, fd);
	param.mlx = mlx_init(find_sizex(param.map),
			find_sizey(param.map), "so_long", false);
	if (!param.mlx || !ft_parsing(&param))
		return (FALSE);
	ft_load_images(&param);
	close(fd);
	ft_place_map(param.map, &param);
	mlx_key_hook(param.mlx, (void (*)(mlx_key_data_t, void *))
		ft_keys, &param);
	mlx_loop(param.mlx);
	free_all(&param);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	game(fd);
}
