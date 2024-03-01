/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:20:06 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/01 23:20:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	assign_player(int *pos, int i, int j, char **map)
{
	pos[0] = i;
	pos[1] = j;
	pos[2] = map[i][j];
}

int	*ft_find_player_pos(char **map)
{
	int	*pos;
	int	i;
	int	j;

	pos = (int *)malloc(sizeof(int) * 3);
	if (!pos)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSWE", map[i][j]) != NULL)
			{
				assign_player(pos, i, j, map);
				return (pos);
			}
			j++;
		}
		i++;
	}
	free(pos);
	return (NULL);
}
