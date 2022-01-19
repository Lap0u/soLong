/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:36:36 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/23 16:01:46 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_solong.h"

void	ft_display_background(char **map, void *mlx, void *mlx_win)
{
	t_xpm	wall;
	t_xpm	spr;
	int		i;
	int		j;

	i = -1;
	spr.path = "./img/spare.xpm";
	spr.img = mlx_xpm_file_to_image(mlx, spr.path, &spr.width, &spr.height);
	ft_check_image(spr.img, mlx, mlx_win, map);
	wall.path = "./img/wall_hole_1.xpm";
	wall.img = mlx_xpm_file_to_image(mlx, wall.path, &wall.width, &wall.height);
	ft_check_image(wall.img, mlx, mlx_win, map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall.img, j * 16, i * 16);
			else
				mlx_put_image_to_window(mlx, mlx_win, spr.img, j * 16, i * 16);
		}
	}
	mlx_destroy_image(mlx, wall.img);
	mlx_destroy_image(mlx, spr.img);
}

void	ft_display_collec(char **map, void *mlx, void *mlx_win)
{
	t_xpm	clc;
	int		i;
	int		j;

	i = 0;
	clc.path = "./img/choco.xpm";
	clc.img = mlx_xpm_file_to_image(mlx, clc.path, &clc.width, &clc.height);
	ft_check_image(clc.img, mlx, mlx_win, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, clc.img, j * 16, i * 16);
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx, clc.img);
}

void	ft_display_player(char **map, void *mlx, void *mlx_win)
{
	t_xpm	pla;
	int		i;
	int		j;

	i = 0;
	pla.path = "./img/vais_D.xpm";
	pla.img = mlx_xpm_file_to_image(mlx, pla.path, &pla.width, &pla.height);
	ft_check_image(pla.img, mlx, mlx_win, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, pla.img, j * 16, i * 16);
				mlx_destroy_image(mlx, pla.img);
				return ;
			}
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx, pla.img);
}

void	ft_display_exit(char **map, void *mlx, void *mlx_win)
{
	t_xpm	exit;
	int		i;
	int		j;

	i = 0;
	exit.path = "./img/door.xpm";
	exit.img = mlx_xpm_file_to_image(mlx, exit.path, &exit.width, &exit.height);
	ft_check_image(exit.img, mlx, mlx_win, map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit.img, j * 16, i * 16);
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx, exit.img);
}

void	ft_display_map(char **map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	ft_display_background(vars.map, vars.mlx, vars.mlx_win);
	ft_display_collec(vars.map, vars.mlx, vars.mlx_win);
	ft_display_player(vars.map, vars.mlx, vars.mlx_win);
	ft_display_exit(vars.map, vars.mlx, vars.mlx_win);
	ft_hooks(&vars);
	mlx_loop(vars.mlx);
}
