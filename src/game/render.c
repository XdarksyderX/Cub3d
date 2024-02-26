/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 11:03:00 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
	mlx_image_to_window(game->mlx, img, (uint32_t) 0, (uint32_t) 0);
}
