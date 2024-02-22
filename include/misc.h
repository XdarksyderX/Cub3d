/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:17:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 21:12:22 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"

# define SPACES " \t\v\r"

typedef struct s_flood
{
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_flood;


void	ft_usage(void);

char	*ft_sanitize_line(char *str);

bool	is_map_fully_enclosed(char **map, int width, int height);

void	ft_free_matrix(void **map, int n);
int		ft_matrix_len(void **matrix);
void	**ft_matrix_dup(void **matrix);

void	ft_free_config(t_config *config);
void	ft_free_map(t_map	*map);

#endif