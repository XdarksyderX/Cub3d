/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 00:43:02 by migarci2         ###   ########.fr       */
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
	printf("WALL_HEIGHT: %d\n", wall_info.wall_height);
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
	printf("RAY_X START: %f\n", ray_x);
	printf("RAY_Y START: %f\n", ray_y);
	if (ft_get_hit_point(&ray_x, &ray_y, angle, game->map))
		ray_info.hit_ratio = fmod(ray_x, TILE_SIZE) / TILE_SIZE;
	else
		ray_info.hit_ratio = fmod(ray_y, TILE_SIZE) / TILE_SIZE;
	ray_info.dist = sqrtf(powf(game->map->player->x - ray_x, 2)
			+ powf(game->map->player->y - ray_y, 2));
	ray_info.dist = ray_info.dist * cosf(game->map->player->angle - angle);
	ray_info.angle = angle;
	ray_info.x = x;
	printf("RAY_X FINAL: %f\n", ray_x);
	printf("RAY_Y FINAL: %f\n", ray_y);
	printf("ANGLE: %f\n", ray_info.angle);
	printf("DIST: %f\n", ray_info.dist);
	printf("HIT_RATIO: %f\n", ray_info.hit_ratio);
	printf("X: %d\n\n", ray_info.x);
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
	uint16_t	y;
	uint32_t	x;
	uint32_t	color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = game->ceiling_color;
			if (y >= WINDOW_HEIGHT / 2)
				color = game->floor_color;
			mlx_put_pixel(img, x, y, (uint32_t) color);
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
		exit(1);
	}
	ft_draw_walls(img, game);
	ft_draw_ceiling_floor(img, game);
	mlx_put_pixel(img, 100, 100, 0xFFFFFFFF);
}
