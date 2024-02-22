/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:21:07 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 21:06:44 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_parse_texture(char **config_line, t_config *config)
{
	if (ft_strncmp(config_line[0], "NO", 2) == 0)
	{
		free(config->north_texture_path);
		config->north_texture_path = ft_strdup(config_line[1]);
	}
	else if (ft_strncmp(config_line[0], "SO", 2) == 0)
	{
		free(config->south_texture_path);
		config->south_texture_path = ft_strdup(config_line[1]);
	}
	else if (ft_strncmp(config_line[0], "EA", 2) == 0)
	{
		free(config->east_texture_path);
		config->east_texture_path = ft_strdup(config_line[1]);
	}
	else if (ft_strncmp(config_line[0], "WE", 2) == 0)
	{
		free(config->west_texture_path);
		config->west_texture_path = ft_strdup(config_line[1]);
	}
}

static void	ft_init(t_config *config)
{
	config->floor_color[0] = -1;
	config->floor_color[1] = -1;
	config->floor_color[2] = -1;
	config->ceiling_color[0] = -1;
	config->ceiling_color[1] = -1;
	config->ceiling_color[2] = -1;
	config->north_texture_path = NULL;
	config->south_texture_path = NULL;
	config->east_texture_path = NULL;
	config->west_texture_path = NULL;
	config->map = NULL;
	config->rows = 0;
	config->cols = 0;
}

static void	ft_get_map(int fd, t_config *config, char *line)
{
	int		i;

	config->map = malloc(sizeof(char *) * (config->rows + 1));
	if (!config->map)
		return ;
	i = 0;
	while (line)
	{
		if (is_map_line(line))
		{
			config->map[i] = ft_strdup(line);
			if (!config->map[i])
			{
				ft_free_matrix((void **)config->map, i);
				config->map = NULL;
				return ;
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	config->map[i] = NULL;
}

static void	ft_parse_line(char *line, t_config *config, int *lock)
{
	char	**config_line;

	if (!line || *lock)
		return ;
	config_line = ft_split(line, ' ');
	if (ft_strlen(config_line[0]) == 2)
		ft_parse_texture(config_line, config);
	else if (ft_strlen(config_line[0]) == 1)
		ft_parse_color(config_line, config);
	else if (is_map_line(line))
		*lock = 1;
	ft_free_matrix((void **)config_line, ft_matrix_len((void **)config_line));
	free(line);
}

t_config	*ft_get_config(char	*config_file)
{
	t_config	*config;
	int				fd;
	char			*line;
	int				lock;

	fd = open(config_file, O_RDONLY);
	config = malloc(sizeof(t_config));
	if (!config || fd < 0)
		return (NULL);
	ft_init(config);
	ft_get_map_size(config_file, config);
	line = get_next_line(fd);
	lock = 0;
	while (line && !lock)
	{
		ft_parse_line(ft_sanitize_line(line), config, &lock);
		if (lock)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	ft_get_map(fd, config, line);
	close(fd);
	return (config);
}
