/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:19:23 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 21:12:02 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_solong.h"

int	ft_minimize(t_vars *vars)
{
	ft_display_background(vars->map, vars->mlx, vars->mlx_win);
	ft_display_collec(vars->map, vars->mlx, vars->mlx_win);
	ft_display_player(vars->map, vars->mlx, vars->mlx_win);
	ft_display_exit(vars->map, vars->mlx, vars->mlx_win);
	return (0);
}

int	ft_escape(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	ft_free_map(vars->map);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

void	ft_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 17, 0, ft_escape, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, ft_move, vars);
	mlx_hook(vars->mlx_win, 12, 1L << 15, ft_minimize, vars);
}

int	ft_move(int keycode, t_vars *vars)
{
	static int	count = 0;
	static int	code = 0x0000FF00;
	char		*score;

	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		count++;
	ft_close(keycode, vars);
	if (keycode == 119)
		ft_forward(vars);
	else if (keycode == 97)
		ft_left(vars);
	else if (keycode == 115)
		ft_backward(vars);
	else if (keycode == 100)
		ft_right(vars);
	ft_display_front_row(vars);
	score = ft_itoa(count);
	mlx_string_put(vars->mlx, vars->mlx_win, 10, 10, code -= 10, score);
	free(score);
	return (0);
}

//	13 0 1 2 53
int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_free_map(vars->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
