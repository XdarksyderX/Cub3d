/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:27 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/21 18:36:57 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

void	ft_usage(void)
{
	printf("Usage: ./cub3d <map_file>\n");
}

bool	ft_have_extension(char *file, char *ext)
{
	int	len;
	int	ext_len;

	len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (len < ext_len)
		return (false);
	return (!ft_strncmp(file + len - ext_len, ext, ext_len));
}
