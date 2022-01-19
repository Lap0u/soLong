/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:24:58 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/23 15:56:01 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"
#include "../global/libft.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_exit_one_mall(char *str)
{
	free(str);
	ft_wrong_malloc();
}

void	ft_display_bg(t_vars *vars, int i, int j)
{
	ft_place_background(vars, i, j);
	ft_display_all(vars->map, vars->mlx, vars->mlx_win);
}
