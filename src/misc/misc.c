/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:27 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/01 23:08:27 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

void	ft_usage(void)
{
	printf("Usage: ./cub3d <map_file.cub>\n");
}

bool	ft_file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
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

uint32_t	mlx_get_pixel_color(mlx_texture_t *texture, uint32_t x, uint32_t y)
{
	uint8_t		*pixel;
	uint32_t	color;

	pixel = &texture->pixels[(y * texture->width + x) * sizeof(uint32_t)];
	color = 0;
	color |= ((uint32_t)pixel[0]) << 24;
	color |= ((uint32_t)pixel[1]) << 16;
	color |= ((uint32_t)pixel[2]) << 8;
	color |= (uint32_t)pixel[3];
	return (color);
}
