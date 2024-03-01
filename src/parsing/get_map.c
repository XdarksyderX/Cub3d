/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:26:29 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/01 23:00:30 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	ft_check_extreme_lines(char *line)
{
	size_t	i;
	size_t	len;

	if (!line)
		return (false);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	len = i;
	while (line[len] && !ft_isspace(line[len]))
		len++;
	if (len == i)
		return (false);
	while (i < len)
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_parse_map_line(char *line, t_config *config, int i)
{
	if (!line || !is_map_line(line))
		return (false);
	if ((i == 0 || i == config->rows - 1) && !ft_check_extreme_lines(line))
		return (false);
	config->map[i] = ft_strdup(line);
	return (true);
}

void	ft_get_map(int fd, t_config *config, char *line)
{
	int		i;

	config->map = malloc(sizeof(char *) * (config->rows + 1));
	if (!config->map)
		return ;
	i = 0;
	while (i < config->rows)
	{
		if (!ft_parse_map_line(line, config, i))
		{
			free(line);
			ft_free_matrix((void **) config->map, i);
			config->map = NULL;
			return ;
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	config->map[i] = NULL;
}
