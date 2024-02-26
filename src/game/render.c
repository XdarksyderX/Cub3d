/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 12:01:00 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_draw_wall(mlx_image_t *img, t_ray_info ray_info, t_game *game)
{
	mlx_texture_t	*texture;
	t_wall_info		wall_info;

	texture = ft_get_texture(ray_info.angle, game);
	wall_info.wall_height = (int)((TILE_SIZE / ray_info.dist)
			* ((WINDOW_WIDTH / 2) / tan(FOV / 2)));
	wall_info.wall_start = (WINDOW_HEIGHT / 2)
				- ((int)((TILE_SIZE / ray_info.dist)
				* ((WINDOW_WIDTH / 2) / tan(FOV / 2))) / 2);
	wall_info.wall_end = (WINDOW_HEIGHT / 2) + ((int)((TILE_SIZE / ray_info.dist)
				* ((WINDOW_WIDTH / 2) / tan(FOV / 2))) / 2);
	if (wall_info.wall_start < 0)
		wall_info.wall_start = 0;
	if (wall_info.wall_end >= WINDOW_HEIGHT)
		wall_info.wall_end = WINDOW_HEIGHT - 1;
	ft_put_wall_line(img, ray_info, wall_info, texture);
}

static	void	ft_cast_ray(mlx_image_t *img, double angle, int x, t_game *game)
{
	double		ray_x;
	double		ray_y;
	t_ray_info	ray_info;

	ray_x = game->map->player->x;
	ray_y = game->map->player->y;
	if (ft_get_hit_point(&ray_x, &ray_y, angle, game->map))
		ray_info.hit_ratio = fmod(ray_x, TILE_SIZE) / TILE_SIZE;
	else
		ray_info.hit_ratio = fmod(ray_y, TILE_SIZE) / TILE_SIZE;
	ray_info.dist = sqrtf(powf(game->map->player->x - ray_x, 2)
			+ powf(game->map->player->y - ray_y, 2));
	ray_info.dist = ray_info.dist * cosf(game->map->player->angle - angle);
	ray_info.angle = angle;
	ray_info.x = x;
	ft_draw_wall(img, ray_info, game);
}

static void	ft_draw_walls(mlx_image_t *img, t_game *game)
{
	int		x;
	double	start_angle;
	double	increment_angle;

	start_angle = game->map->player->angle - (FOV / 2);
	increment_angle = FOV / WINDOW_WIDTH;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ft_cast_ray(img, start_angle + increment_angle * x, x, game);
		x++;
	}
}

static void	ft_draw_ceiling_floor(mlx_image_t *img, t_game *game)
{
	uint32_t	y;
	uint32_t	x;
	uint32_t	color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = game->ceiling_color;
			if (y <= WINDOW_HEIGHT / 2)
				color = game->floor_color;
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_render(t_game *game)
{
	mlx_image_t	*img;

	img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img)
	{
		ft_free_game(game);
		ft_putstr_fd("Error\nFailed to create image\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_draw_ceiling_floor(img, game);
	ft_draw_walls(img, game);
	mlx_image_to_window(game->mlx, img, (uint32_t) 0, (uint32_t) 0);
}
