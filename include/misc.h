/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:17:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 16:56:29 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "MLX42.h"
# include "libft.h"
# include "parsing.h"

# define PI 3.14159265359
# define PI_2 1.57079632679
# define PI3_2 4.71238898038

# define SPACES " \t\v\r"

# define WALL '1'
# define OPEN '0'
# define FILLED '2'

typedef struct s_flood
{
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_flood;

void		ft_usage(void);

char		*ft_sanitize_line(char *str);

bool		is_map_fully_enclosed(char **map, int width, int height);

void		ft_free_matrix(void **map, int n);
bool		ft_have_extension(char *file, char *ext);
int			ft_matrix_len(void **matrix);
void		**ft_matrix_dup(void **matrix);
uint32_t	ft_apply_shade(uint32_t color, float shade_factor);

#endif