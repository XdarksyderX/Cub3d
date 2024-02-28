/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:45:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 14:19:18 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_calc_dist(t_ray_info *ray_info, t_map *map)
{
	double	dist_x;
	double	dist_y;

	dist_x = ray_info->ray_x - map->player->x;
	dist_y = ray_info->ray_y - map->player->y;
	ray_info->dist = sqrt(dist_x * dist_x + dist_y * dist_y);
	ray_info->dist *= cos(ray_info->angle - map->player->angle);
}

static bool	ft_is_wall(double x, double y, t_map *map)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (map_x < 0 || map_x >= map->width || map_y < 0 || map_y >= map->height)
		return (true);
	if (map->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

//TRUE: HIT HORIZONTAL | FALSE: HIT VERTICAL
void	ft_get_hit_point(t_ray_info *ray_info, t_map *map)
{
	ray_info->x_prev = ray_info->ray_x;
	ray_info->y_prev = ray_info->ray_y;
	ray_info->x_step = cos(ray_info->angle) * STEP_SIZE;
	ray_info->y_step = sin(ray_info->angle) * STEP_SIZE;
	while (!ft_is_wall(ray_info->ray_x, ray_info->ray_y, map))
	{
		ray_info->x_prev = ray_info->ray_x;
		ray_info->y_prev = ray_info->ray_y;
		ray_info->ray_x += ray_info->x_step;
		ray_info->ray_y += ray_info->y_step;
	}
	if (fabs(ray_info->ray_y - ray_info->y_prev)
		< fabs(ray_info->ray_x - ray_info->x_prev))
	{
		ray_info->is_hit_horizontal = true;
		ray_info->hit_ratio = fmod(ray_info->ray_x, TILE_SIZE) / TILE_SIZE;
	}
	else
	{
		ray_info->is_hit_horizontal = false;
		ray_info->hit_ratio = fmod(ray_info->ray_y, TILE_SIZE) / TILE_SIZE;
	}
	ft_calc_dist(ray_info, map);
}

int	ft_get_hit_direction(t_ray_info *ray_info)
{
	int	local_x;
	int	local_y;

	local_x = (int)ray_info->ray_x % 64;
	local_y = (int)ray_info->ray_y % 64;

	if (local_x == 63 && (local_y >= 0 && local_y <= 63))
		return (0);
	else if (local_y == 0 && (local_x >= 0 && local_x <= 63))
		return (1);
	else if (local_y == 63 && (local_x >= 0 && local_x <= 63))
		return (2);
	else if (local_x == 0 && (local_y >= 0 && local_y <= 63))
		return (3);
	else
		return (-1);
}
