/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 21:53:09 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static uint32_t	ft_pixel(int color[3])
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

static void	ft_draw_sky_floor(void	*img, t_game *game)
{
	int			y;
	int			x;
	uint32_t	color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			color = ft_pixel(game->ceiling_color);
			if (y >= WINDOW_HEIGHT / 2)
				color = ft_pixel(game->floor_color);
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_render(t_game *game)
{
	void		*img;

	img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img)
	{
		ft_free_game(game);
		ft_putstr_fd("Error\nFailed to create image\n", 2);
		exit(1);
	}
	ft_draw_sky_floor(img, game);
	mlx_image_to_window(game->mlx, img, 0, 0);
}
