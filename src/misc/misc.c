/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:27 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 17:54:45 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

void	ft_usage(void)
{
	printf("Usage: ./cub3d <map_file.cub>\n");
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

uint32_t	ft_apply_shade(uint32_t color, float shade_factor)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;

	shade_factor = fmax(0, fmin(shade_factor, 1));
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	alpha = (color >> 24) & 0xFF;
	red = (uint8_t)(red * shade_factor);
	green = (uint8_t)(green * shade_factor);
	blue = (uint8_t)(blue * shade_factor);
	return (red << 24 | green << 16 | blue << 8 | alpha);
}
