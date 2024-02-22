/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:15:47 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/21 20:05:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_parse_color(char	**config_line, t_map_config *config)
{
	char	**colors;

	colors = ft_split(config_line[1], ',');
	if (!colors)
		return ;
	if (ft_matrix_len((void **) colors) != 3)
	{
		ft_free_matrix((void **) colors, ft_matrix_len((void **) colors));
		return ;
	}
	if (ft_strncmp(config_line[0], "F ", 1) == 0)
	{
		config->floor_color[0] = ft_atoi(colors[0]);
		config->floor_color[1] = ft_atoi(colors[1]);
		config->floor_color[2] = ft_atoi(colors[2]);
	}
	else if (ft_strncmp(config_line[0], "C ", 1) == 0)
	{
		config->ceiling_color[0] = ft_atoi(colors[0]);
		config->ceiling_color[1] = ft_atoi(colors[1]);
		config->ceiling_color[2] = ft_atoi(colors[2]);
	}
	ft_free_matrix((void **) colors, ft_matrix_len((void **) colors));
}

void	ft_fix_color(t_map_config *config)
{
	if (!ft_valid_color(config->floor_color))
	{
		config->floor_color[0] = -1;
		config->floor_color[1] = -1;
		config->floor_color[2] = -1;
	}
	if (!ft_valid_color(config->ceiling_color))
	{
		config->ceiling_color[0] = -1;
		config->ceiling_color[1] = -1;
		config->ceiling_color[2] = -1;
	}
}

bool	ft_valid_color(int color[3])
{
	if (color[0] < 0 || color[0] > 255)
		return (false);
	if (color[1] < 0 || color[1] > 255)
		return (false);
	if (color[2] < 0 || color[2] > 255)
		return (false);
	return (true);
}
