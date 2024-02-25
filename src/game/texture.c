/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:19:35 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/25 22:48:59 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*ft_get_texture(double angle, t_game *game)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	if (angle >= 0 && angle < PI / 2)
		return (game->textures[EAST_TEXTURE]);
	else if (angle >= PI / 2 && angle < PI)
		return (game->textures[NORTH_TEXTURE]);
	else if (angle >= PI && angle < 3 * PI / 2)
		return (game->textures[WEST_TEXTURE]);
	else if (angle >= 3 * PI / 2 && angle < 2 * PI)
		return (game->textures[SOUTH_TEXTURE]);
	return (NULL);
}

uint32_t	ft_get_texture_pixel(double x, double y, mlx_texture_t *texture)
{
	uint32_t	color;
	int			tex_x;
	int			tex_y;

	tex_x = (int)(x * texture->width);
	tex_y = (int)(y * texture->height);
	printf("X: %f\n", x);
	printf("Y: %f\n", y);
	printf("WIDTH: %d\n", texture->width);
	printf("HEIGHT: %d\n", texture->height);
	tex_x = fmax(0, fmin(tex_x, texture->width - 1));
	tex_y = fmax(0, fmin(tex_y, texture->height - 1));
	printf("TEX_X: %d\n", tex_x);
	printf("TEX_Y: %d\n", tex_y);
	color = texture->pixels[tex_y * texture->width + tex_x];
	printf("COLOR: %X\n", color);
	return (color);
}

double	ft_get_tex_y(int y, t_wall_info wall_info)
{
	double	normalized_y;

	normalized_y = (double)(y - wall_info.wall_start)
		/ (double)wall_info.wall_height;
	return (fmax(0, fmin(normalized_y, 1)));
}

double	ft_get_tex_x(double hit_ratio)
{
	if (hit_ratio < 0)
		hit_ratio = 0;
	if (hit_ratio > 1)
		hit_ratio = 1;
	return (hit_ratio);
}

void	ft_put_wall_line(mlx_image_t *img, t_ray_info ray_info,
	t_wall_info wall_info, mlx_texture_t *texture)
{
	int				y;
	double			tex_x;
	double			tex_y;
	uint32_t		color;

	y = wall_info.wall_start;
	while (y < wall_info.wall_end)
	{
		tex_x = ft_get_tex_x(ray_info.hit_ratio);
		tex_y = ft_get_tex_y(y, wall_info);
		color = ft_get_texture_pixel(tex_x, tex_y, texture);
		mlx_put_pixel(img, ray_info.x, y, color);
		y++;
	}
}
