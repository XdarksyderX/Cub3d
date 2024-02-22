/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:55:15 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 21:06:44 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_map_char(char c)
{
	const char	*map_chars = "01 NSWE";
	int			i;

	i = 0;
	while (map_chars[i] != '\0')
	{
		if (c == map_chars[i])
			return (true);
		i++;
	}
	return (false);
}

bool	is_map_line(const char *line)
{
	size_t	i;
	size_t	len;

	if (!line)
		return (false);
	len = ft_strlen(line);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (len < 2 || line[i] != '1' || line[len - 1] != '1')
		return (false);
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ft_get_map_size(char *config_file, t_config *config)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(config_file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			line_length = ft_strlen(line);
			if (line_length > config->cols)
				config->cols = line_length;
			config->rows++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
