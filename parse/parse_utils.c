/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:32:01 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 21:23:18 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_solong.h"

int	ft_open_map(char *map)
{
	char	str[10];
	int		fd;
	int		bytes;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error while opening file, exiting..\n");
		exit(EXIT_SUCCESS);
	}
	bytes = read(fd, str, 2);
	close(fd);
	if (bytes < 0)
	{
		printf("Error, trying to read from directory, exiting...\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(map, O_RDONLY);
	if (fd < 0 || bytes < 2)
	{
		printf("Error while opening file, exiting..\n");
		exit(EXIT_SUCCESS);
	}
	return (fd);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
