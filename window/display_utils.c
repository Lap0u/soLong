/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:51:51 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/22 15:31:09 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"
#include "../global/libft.h"

void	ft_endgame(t_vars *vars)
{
	ft_free_map(vars->map);
	vars->map = NULL;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	vars->mlx_win = NULL;
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(EXIT_SUCCESS);
}

void	ft_update_map(t_vars *vars, int info)
{
	int		i;
	int		j;

	ft_find_player(&i, &j, vars->map);
	if ((info == 0 && vars->map[i - 1][j] == 'E') ||
		(info == 1 && vars->map[i][j + 1] == 'E') ||
		(info == 2 && vars->map[i + 1][j] == 'E') ||
	   	(info == 3 && vars->map[i][j - 1] == 'E'))
		ft_endgame(vars);
	vars->map[i][j] = '0';
	if (info == 0)
		vars->map[i - 1][j] = 'P';
	else if (info == 1)
		vars->map[i][j + 1] = 'P';
	else if (info == 2)
		vars->map[i + 1][j] = 'P';
	else if (info == 3)
		vars->map[i][j - 1] = 'P';
}

int	ft_more_collec(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_endgame(int i, int j, int info, char **map)
{
	if (info == 0)
	{
		if (map[i - 1][j] == 'E' && ft_more_collec(map) == 0)
			return (1);
	}
	else if (info == 1)
	{
		if (map[i][j + 1] == 'E' && ft_more_collec(map) == 0)
			return (1);
	}
	else if (info == 2)
	{
		if (map[i + 1][j] == 'E' && ft_more_collec(map) == 0)
			return (1);
	}
	else if (info == 3)
	{
		if (map[i][j - 1] == 'E' && ft_more_collec(map) == 0)
			return (1);
	}
	return (0);
}

int	ft_check_move(int i, int j, int info, char **map)
{
	if (ft_check_endgame(i, j, info, map) == 1)
		return (1);
	if (info == 0)
	{
		if (map[i - 1][j] == '1' || map[i - 1][j] == 'E')
			return (0);
	}
	else if (info == 1)
	{
		if (map[i][j + 1] == '1' || map[i][j + 1] == 'E')
			return (0);
	}
	else if (info == 2)
	{
		if (map[i + 1][j] == '1' || map[i + 1][j] == 'E')
			return (0);
	}
	else if (info == 3)
	{
		if (map[i][j - 1] == '1' || map[i][j - 1] == 'E')
			return (0);
	}
	return (1);
}
