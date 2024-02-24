/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:59:41 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 18:30:37 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_close(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	mlx_close_window(game->mlx);
	ft_free_game(game);
	exit(0);
}


void	ft_setup_hooks(t_game *game)
{
	mlx_close_hook(game->mlx, ft_close, game);
}
