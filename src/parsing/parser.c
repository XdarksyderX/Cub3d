/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:21:07 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:43:51 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_check_end(t_config *config, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0
			&& ft_count_space(line, SPACES) != (int) ft_strlen(line))
		{
			free(line);
			ft_free_config(config);
			config = NULL;
			ft_putstr_fd("Error\nInvalid configuration file\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

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
	int			fd;
	char		*line;
	int			lock;

	fd = open(config_file, O_RDONLY);
	config = malloc(sizeof(t_config));
	if (!config || fd < 0)
		return (free(config), NULL);
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
	ft_check_end(config, fd);
	close(fd);
	return (config);
}
