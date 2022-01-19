/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:38:42 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/22 14:34:10 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_solong.h"

void	ft_check_image(void *img, void *mlx, void *win, char **map)
{
	if (img == NULL)
	{
		ft_free_map(map);
		map = NULL;
		mlx_destroy_window(mlx, win);
		win = NULL;
		mlx_destroy_display(mlx);
		free(mlx);
		mlx = NULL;
		ft_wrong_image();
	}
}

void	ft_img_to_win(t_vars *vars, t_xpm *pla, int j, int i)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, pla->img, j, i);
}

void	ft_display_all(char **map, void *mlx, void *win)
{
	ft_display_collec(map, mlx, win);
	ft_display_exit(map, mlx, win);
}

void	ft_display_front_row(t_vars *vars)
{
	t_xpm	wl;
	int		i;

	i = 0;
	wl.path = "./img/wall_hole_1.xpm";
	wl.img = mlx_xpm_file_to_image(vars->mlx, wl.path, &wl.width, &wl.height);
	ft_check_image(wl.img, vars->mlx, vars->mlx_win, vars->map);
	while (vars->map[0][i])
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, wl.img, i * 16, 0);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, wl.img, 0, 16);
	mlx_destroy_image(vars->mlx, wl.img);
}

void	ft_place_background(t_vars *vars, int i, int j)
{
	t_xpm	sp;

	sp.path = "./img/spare.xpm";
	sp.img = mlx_xpm_file_to_image(vars->mlx, sp.path, &sp.width, &sp.height);
	ft_check_image(sp.img, vars->mlx, vars->mlx_win, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, sp.img, j * 16, i * 16);
	mlx_destroy_image(vars->mlx, sp.img);
}
