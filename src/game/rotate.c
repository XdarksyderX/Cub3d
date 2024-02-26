/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:25 by jzaragoz          #+#    #+#             */
/*   Updated: 2024/02/26 19:01:22 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	ft_rotate(t_game *game, int key)
{
	if (key == LEFT_ARROW_KEY)
	{
		game->map->player->angle -= ANGLE_STEP * game->mlx->delta_time;
		if (game->map->player->angle < 0)
		{
			game->map->player->angle += 2 * PI;
		}
		return (true);
	}
	else if (key == RIGHT_ARROW_KEY)
	{
		game->map->player->angle += ANGLE_STEP * game->mlx->delta_time;
		if (game->map->player->angle >= 2 * PI)
		{
			game->map->player->angle -= 2 * PI;
		}
		return (true);
	}
	return (false);
}
