/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:19:35 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 14:19:52 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*ft_get_texture(t_ray_info ray_info, t_game *game)
{
	return (game->textures[ft_get_hit_direction(&ray_info)]);
}

uint32_t	ft_get_texture_pixel(double x, double y, mlx_texture_t *texture)
{
	uint32_t	color;
	int			tex_x;
	int			tex_y;

	tex_x = (int)(x * texture->width);
	tex_y = (int)(y * texture->height);
	tex_x = fmax(0, fmin(tex_x, texture->width - 1));
	tex_y = fmax(0, fmin(tex_y, texture->height - 1));
	color = mlx_get_pixel_color(texture, tex_x, tex_y);
	return (color);
}
