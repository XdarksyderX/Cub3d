/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 12:11:48 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_draw_wall(mlx_image_t *img, t_ray_info ray_info, t_game *game)
{
	t_wall_info		wall_info;

	wall_info.texture = ft_get_texture(ray_info, game);
	wall_info.wall_height = (int)((TILE_SIZE / ray_info.dist)
			* ((WINDOW_WIDTH / 2) / tan(FOV / 2)));
	wall_info.wall_start = (WINDOW_HEIGHT / 2) - (wall_info.wall_height / 2);
	wall_info.wall_end = wall_info.wall_start + wall_info.wall_height;
	if (wall_info.wall_start < 0)
		wall_info.wall_start = 0;
	if (wall_info.wall_end >= WINDOW_HEIGHT)
		wall_info.wall_end = WINDOW_HEIGHT - 1;
	wall_info.ray_info = ray_info;
	ft_put_line(img, (int[2]){0, wall_info.wall_start},
		ray_info.x, game->ceiling_color);
	ft_put_wall_line(img, wall_info);
	ft_put_line(img, (int[2]) {wall_info.wall_end, WINDOW_HEIGHT},
		ray_info.x, game->floor_color);
}

static void	ft_cast_ray(mlx_image_t *img, int x, t_game *game)
{
	t_ray_info	ray_info;

	ft_bzero(&ray_info, sizeof(ray_info));
	ray_info.angle = game->map->player->angle
		- (FOV / 2) + (x * (FOV / WINDOW_WIDTH));
	ray_info.ray_x = game->map->player->x;
	ray_info.ray_y = game->map->player->y;
	ft_get_hit_point(&ray_info, game->map);
	ray_info.x = x;
	ft_draw_wall(img, ray_info, game);
}

static void	ft_draw_walls(mlx_image_t *img, t_game *game)
{
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ft_cast_ray(img, x, game);
		x++;
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
	mlx_delete_image(game->mlx, game->last_frame);
	ft_draw_walls(img, game);
	game->last_frame = img;
	mlx_image_to_window(game->mlx, img, (uint32_t) 0, (uint32_t) 0);
}
