/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:16:43 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/21 19:37:59 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>

# include "misc.h"

# define MAP_CHARS "01 NSWE"

typedef struct s_map_config
{
	char			**map;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*east_texture_path;
	char			*west_texture_path;
	int				floor_color[3];
	int				ceiling_color[3];
	int				rows;
	int				cols;
}				t_map_config;

void			ft_parse_color(char	**config_line, t_map_config *config);
bool			ft_valid_color(int color[3]);

void			ft_get_map_size(char *config_file, t_map_config *config);
bool			is_map_line(const char *line);
t_map_config	*ft_get_config(char	*config_file);
int				*ft_find_player_pos(char **map);

bool			ft_check_config(t_map_config *config);

void			ft_debug_config(t_map_config *config);

#endif