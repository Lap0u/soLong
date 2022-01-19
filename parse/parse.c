/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:57:09 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 20:49:18 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"
#include "../global/libft.h"

void	ft_remove_starting(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{	
			if (map[i][j] == 'P' && count == 1)
				map[i][j] = '0';
			if (map[i][j] == 'P')
				count = 1;
			j++;
		}
		i++;
	}
}

char	**ft_check_map(char *res)
{
	char	**map;

	map = ft_split(res, '\n');
	if (ft_check_walls(map) == 0 || ft_check_collec(map) == 0
		|| ft_check_start(map) == 0 || ft_check_exit(map) == 0
		|| ft_check_inside(map) == 0)
	{
		ft_free_map(map);
		return (NULL);
	}
	ft_remove_starting(map);
	return (map);
}

int	ft_parse_arg(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) < 4)
		return (0);
	while (str[i])
		i++;
	if (ft_strncmp(str + i - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	**ft_parse_map(char *arg)
{
	int		fd;
	char	**line;
	char	*res;
	char	**map;

	res = NULL;
	fd = ft_open_map(arg);
	line = malloc(sizeof(char *) * 50);
	if (line == NULL)
		ft_wrong_malloc();
	while (1)
	{
		get_next_line(fd, line);
		if (*line[0] == '\0')
			break ;
		res = ft_all_line(*line, res);
	}
	free(*line);
	free(line);
	close(fd);
	map = ft_check_map(res);
	free(res);
	return (map);
}
