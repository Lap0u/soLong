/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 04:40:11 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/23 15:49:24 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"
#include "../global/libft.h"

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

char	*ft_scopy(char *dest)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(dest) + 2);
	if (res == NULL)
	{
		free(dest);
		ft_wrong_malloc();
	}
	while (dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	res[i] = '\n';
	res[i + 1] = '\0';
	free(dest);
	return (res);
}

char	*ft_scat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_strlen(dest) + ft_strlen(src) + 2);
	if (res == NULL)
		ft_exit_two_mall(dest, src);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	while (dest[j])
	{
		res[i + j] = dest[j];
		j++;
	}
	res[i + j] = '\n';
	res[i + j + 1] = '\0';
	free(dest);
	free(src);
	return (res);
}

char	*ft_all_line(char *line, char *dest)
{
	char	*temp;

	if (dest == NULL)
	{
		dest = ft_scopy(line);
		if (dest == NULL)
			ft_exit_one_mall(line);
		return (dest);
	}
	else
	{
		temp = ft_scopy(dest);
		if (temp == NULL)
			ft_exit_one_mall(line);
		temp = ft_scat(line, temp);
		if (dest == NULL)
			ft_exit_one_mall(line);
		return (temp);
	}
}
