/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:17:18 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/20 22:38:41 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"

# define SPACES " \t\v\r"

void	ft_usage(void);

char	*ft_sanitize_line(char *str);

void	ft_free_matrix(void **map, int n);
int		ft_matrix_len(void **matrix);


#endif