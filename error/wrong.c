/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 02:09:15 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/22 13:34:20 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_solong.h"

void	ft_exit_two_mall(char *str, char *str2)
{
	free(str);
	free(str2);
	ft_wrong_malloc();
}

void	ft_wrong_image(void)
{
	printf("Error during image opening, exiting.. \n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_arg(void)
{
	printf("Error wrong argument, one .ber map allowed only,exiting..\n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_map(void)
{
	printf("Error wrong map configuration, exiting..\n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_malloc(void)
{
	printf("Error during memory allocation, exiting..\n");
	exit(EXIT_SUCCESS);
}
