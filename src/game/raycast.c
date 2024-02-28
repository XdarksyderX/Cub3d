/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:45:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 21:07:45 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

static	void	ft_init_ray(t_ray_info *r, double angle, t_game *game)
{
	r->dir[X] = cos(angle);
	r->dir[Y] = sin(angle);
	r->step_size[X] = sqrt(1 + pow(r->dir[Y] / r->dir[X], 2));
	r->step_size[Y] = sqrt(1 + pow(r->dir[X] / r->dir[Y], 2));
	r->player[X] = game->map->player->x;
	r->player[Y] = game->map->player->y;
	r->map_check[X] = (int)r->player[X];
	r->map_check[Y] = (int)r->player[Y];
	r->is_vertical = false;
	if (r->dir[X] < 0)
		r->len[X] = (r->player[X] - (double) r->map_check[X]) * r->step_size[X];
	else
		r->len[X] = ((double) r->map_check[X] + 1.0 - r->player[X]) * r->step_size[X];
	r->step[X] = 1 - (r->dir[X] < 0) * 2;
	if (r->dir[Y] < 0)
		r->len[Y] = (r->player[Y] - (double) r->map_check[Y]) * r->step_size[Y];
	else
		r->len[Y] = ((double) r->map_check[Y] + 1.0 - r->player[Y]) * r->step_size[Y];
	r->step[Y] = 1 - (r->dir[Y] < 0) * 2;
}

static void	ft_ray_loop(t_game *game, t_ray_info *r)
{
	while (ft_is_wall(r->map_check[X], r->map_check[Y], game->map) == false)
	{
		if (r->len[X] < r->len[Y])
		{
			r->map_check[X] += r->step[X];
			r->dist = r->len[X];
			r->is_vertical = true;
			r->len[X] += r->step_size[X];
		}
		else
		{
			r->map_check[Y] += r->step[Y];
			r->dist = r->len[Y];
			r->is_vertical = false;
			r->len[Y] += r->step_size[Y];
		}
	}
}

void	ft_ray(t_game *game, double angle, t_ray_info *r)
{
	ft_init_ray(r, angle, game);
	ft_ray_loop(game, r);
	r->hit[X] = r->player[X] + r->dir[X] * r->dist;
	r->hit[Y] = r->player[Y] + r->dir[Y] * r->dist;
	r->dist *= cos(angle - game->map->player->angle);
}
