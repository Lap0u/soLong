/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 01:56:37 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/22 13:31:01 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_solong.h"

int	main(int ac, char **argv)
{
	char	**map;

	map = NULL;
	if (ac != 2 || ft_parse_arg(argv[1]) == 0)
		ft_wrong_arg();
	else
		map = ft_parse_map(argv[1]);
	if (map == NULL)
		ft_wrong_map();
	ft_display_map(map);
	return (0);
}
