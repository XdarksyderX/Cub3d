/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:26:29 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:13:44 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	ft_parse_map_line(char *line, t_config *config, int i)
{
	if (!line || !is_map_line(line))
		return (false);
	config->map[i] = ft_strdup(line);
	if (!config->map[i])
		return (false);
	return (true);
}

void	ft_get_map(int fd, t_config *config, char *line)
{
	int	i;

	config->map = malloc(sizeof(char *) * (config->rows + 1));
	if (!config->map)
		return ;
	i = 0;
	while (i < config->rows && line)
	{
		if (!ft_parse_map_line(line, config, i))
		{
			free(line);
			ft_free_matrix((void **)config->map, i);
			config->map = NULL;
			return ;
		}
		free(line);
		if (i < config->rows - 1)
			line = get_next_line(fd);
		i++;
	}
	config->map[i] = NULL;
}
