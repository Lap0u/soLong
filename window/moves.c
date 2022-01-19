/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:18:54 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/23 15:59:55 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"
#include "../global/libft.h"

void	ft_find_player(int *i, int *j, char **map)
{
	int		k;
	int		l;

	k = 1;
	while (map[k])
	{
		l = 1;
		while (map[k][l])
		{
			if (map[k][l] == 'P')
			{
				*i = k;
				*j = l;
				return ;
			}
			l++;
		}
		k++;
	}
}

void	ft_forward(t_vars *vars)
{
	t_xpm	p;
	int		i;
	int		j;
	int		count;

	count = -1;
	ft_find_player(&i, &j, vars->map);
	p.path = "img/vais_U.xpm";
	p.img = mlx_xpm_file_to_image(vars->mlx, p.path, &p.width, &p.height);
	ft_check_image(p.img, vars->mlx, vars->mlx_win, vars->map);
	ft_place_background(vars, i, j);
	ft_img_to_win(vars, &p, j * 16, i * 16);
	if (ft_check_move(i, j, 0, vars->map) == 0)
	{
		mlx_destroy_image(vars->mlx, p.img);
		return ;
	}
	while (++count < 16)
	{
		ft_display_bg(vars, i, j);
		ft_img_to_win(vars, &p, j * 16, i * 16 - count);
		mlx_do_sync(vars->mlx);
	}
	mlx_destroy_image(vars->mlx, p.img);
	ft_update_map(vars, 0);
}

void	ft_left(t_vars *vars)
{
	t_xpm	p;
	int		i;
	int		j;
	int		count;

	count = -1;
	ft_find_player(&i, &j, vars->map);
	p.path = "img/vais_L.xpm";
	p.img = mlx_xpm_file_to_image(vars->mlx, p.path, &p.width, &p.height);
	ft_check_image(p.img, vars->mlx, vars->mlx_win, vars->map);
	ft_place_background(vars, i, j);
	ft_img_to_win(vars, &p, j * 16, i * 16);
	if (ft_check_move(i, j, 3, vars->map) == 0)
	{
		mlx_destroy_image(vars->mlx, p.img);
		return ;
	}
	while (++count < 16)
	{
		ft_display_bg(vars, i, j);
		ft_img_to_win(vars, &p, j * 16 - count, i * 16);
		mlx_do_sync(vars->mlx);
	}
	mlx_destroy_image(vars->mlx, p.img);
	ft_update_map(vars, 3);
}

void	ft_backward(t_vars *vars)
{
	t_xpm	p;
	int		i;
	int		j;
	int		count;

	count = -1;
	ft_find_player(&i, &j, vars->map);
	p.path = "img/vais_D.xpm";
	p.img = mlx_xpm_file_to_image(vars->mlx, p.path, &p.width, &p.height);
	ft_check_image(p.img, vars->mlx, vars->mlx_win, vars->map);
	ft_place_background(vars, i, j);
	ft_img_to_win(vars, &p, j * 16, i * 16);
	if (ft_check_move(i, j, 2, vars->map) == 0)
	{
		mlx_destroy_image(vars->mlx, p.img);
		return ;
	}
	while (++count < 16)
	{
		ft_display_bg(vars, i, j);
		ft_img_to_win(vars, &p, j * 16, i * 16 + count);
		mlx_do_sync(vars->mlx);
	}
	mlx_destroy_image(vars->mlx, p.img);
	ft_update_map(vars, 2);
}

void	ft_right(t_vars *vars)
{
	t_xpm	p;
	int		i;
	int		j;
	int		count;

	count = -1;
	ft_find_player(&i, &j, vars->map);
	p.path = "img/vais_R.xpm";
	p.img = mlx_xpm_file_to_image(vars->mlx, p.path, &p.width, &p.height);
	ft_check_image(p.img, vars->mlx, vars->mlx_win, vars->map);
	ft_place_background(vars, i, j);
	ft_img_to_win(vars, &p, j * 16, i * 16);
	if (ft_check_move(i, j, 1, vars->map) == 0)
	{
		mlx_destroy_image(vars->mlx, p.img);
		return ;
	}
	while (++count < 16)
	{
		ft_display_bg(vars, i, j);
		ft_img_to_win(vars, &p, j * 16 + count, i * 16);
		mlx_do_sync(vars->mlx);
	}
	mlx_destroy_image(vars->mlx, p.img);
	ft_update_map(vars, 1);
}
