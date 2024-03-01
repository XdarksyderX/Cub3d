/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:55:15 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/01 23:00:41 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_meassure_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(SPACES, str[i]) == NULL)
		i++;
	return (i);
}

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
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	len = ft_meassure_line(line + i);
	if (line[i] != '1' || line[len - 1] != '1')
		return (false);
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	ft_update_map_size(t_config *config, const char *line)
{
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length > config->cols)
		config->cols = line_length;
	config->rows++;
}

void	ft_get_map_size(char *config_file, t_config *config)
{
	int		fd;
	char	*line;
	bool	locked;

	fd = open(config_file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	locked = false;
	while (line)
	{
		if (is_map_line(line))
		{
			locked = true;
			ft_update_map_size(config, line);
		}
		if (locked && !is_map_line(line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
