/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:32:47 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/21 15:05:39 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_debug_config(t_map_config *config)
{
	int	i;

	printf("North Texture: %s\n", config->north_texture_path);
	printf("South Texture: %s\n", config->south_texture_path);
	printf("West Texture: %s\n", config->west_texture_path);
	printf("East Texture: %s\n", config->east_texture_path);
	printf("Floor color: %d, %d, %d\n",
		config->floor_color[0], config->floor_color[1], config->floor_color[2]);
	printf("Ceiling color: %d, %d, %d\n",
		config->ceiling_color[0],
		config->ceiling_color[1], config->ceiling_color[2]);
	printf("Rows: %d\n", config->rows);
	printf("Cols: %d\n", config->cols);
	printf("Map:\n");
	i = 0;
	while (i < config->rows)
	{
		printf("%s\n", config->map[i]);
		i++;
	}
}
