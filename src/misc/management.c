/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:12:40 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/20 22:42:07 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

void	ft_free_matrix(void **map, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(((unsigned char **)map)[i]);
		i++;
	}
	free(map);
}

int	ft_matrix_len(void **matrix)
{
	int	i;

	i = 0;
	while (((unsigned char **) matrix)[i] != NULL)
		i++;
	return (i);
}
