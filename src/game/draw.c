/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:22:43 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 21:24:25 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_put_line(mlx_image_t *img, int pos[2], int x, uint32_t color)
{
	int		y;

	y = pos[0];
	while (y < pos[1])
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}

static double	ft_get_tex_y(int y, t_wall_info wall_info)
{
	double	normalized_y;

	normalized_y = ((double)(y - wall_info.wall_start))
		/ (double)wall_info.wall_height;
	return (fmax(0, fmin(normalized_y, 1)));
}

void	ft_put_wall_line(mlx_image_t *img, t_wall_info wall_info)
{
	int				y;
	double			tex_x;
	double			tex_y;
	uint32_t		color;

	if (wall_info.wall_start < 0)
		wall_info.texture_offset = -wall_info.wall_start;
	y = fmax(0, wall_info.wall_start);
	while (y < wall_info.wall_end)
	{
		tex_x = wall_info.ray_info.hit_ratio;
		tex_y = ft_get_tex_y(y, wall_info);
		color = ft_get_texture_pixel(tex_x, tex_y, wall_info.texture);
		mlx_put_pixel(img, wall_info.ray_info.x, y, color);
		y++;
	}
}
