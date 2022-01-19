/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_solong.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:57:43 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/23 15:55:18 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SOLONG_H
# define LIB_SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx_linux/mlx.h"

//# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}				t_data;

typedef struct s_xpm
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}				t_xpm;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
}				t_vars;

int		ft_parse_arg(char *arg);

char	**ft_parse_map(char *map);

void	ft_wrong_arg(void);

void	ft_wrong_image(void);

void	ft_wrong_map(void);

int		ft_open_map(char *map);

void	ft_wrong_malloc(void);

void	ft_exit_one_mall(char *str);

void	ft_exit_two_mall(char *str, char *str2);

char	*ft_all_line(char *line, char *res);

char	**ft_check_map(char *res);

void	ft_remove_starting(char **map);

int		ft_check_walls(char **map);

int		ft_check_collec(char **map);

int		ft_check_start(char **map);

int		ft_check_exit(char **map);

int		ft_check_inside(char **map);

void	ft_free_map(char **map);

void	ft_print_map(char **map);

void	ft_pixel_put(t_data *data, int x, int y, int color);

void	ft_img_to_win(t_vars *vars, t_xpm *pla, int j, int i);

void	ft_display_map(char **map);

void	ft_display_background(char **map, void *mlx, void *mlx_win);

void	ft_display_bg(t_vars *vars, int i, int j);

void	ft_place_background(t_vars *vars, int i, int j);

void	ft_display_collec(char **map, void *mlx, void *mlx_win);

void	ft_display_player(char **map, void *mlx, void *mlx_win);

void	ft_display_exit(char **map, void *mlx, void *mlx_win);

int		ft_close(int keycode, t_vars *vars);

void	ft_hooks(t_vars *vars);

int		ft_move(int keycode, t_vars *vars);

void	ft_forward(t_vars *vars);

void	ft_left(t_vars *vars);

void	ft_backward(t_vars *vars);

void	ft_right(t_vars *vars);

void	ft_find_player(int *i, int *j, char **map);

void	ft_update_map(t_vars *vars, int info);

int		ft_check_move(int i, int j, int info, char **map);

void	ft_display_front_row(t_vars *vars);

void	ft_display_all(char **map, void *mlx, void *win);

void	ft_check_image(void *img, void *mlx, void *win, char **map);

#endif
