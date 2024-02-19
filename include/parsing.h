/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:16:43 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 22:46:42 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "misc.h"

typedef struct s_map_config
{
	char			**map;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*east_texture_path;
	char			*west_texture_path;
	unsigned char	floor_color[3];
	unsigned char	ceiling_color[3];
	int				rows;
	int				cols;
}				t_map_config;

#endif