/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:59:41 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 12:05:33 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_close(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	mlx_close_window(game->mlx);
	ft_free_game(game);
	exit(0);
}

static void	ft_esc(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_close(game);
}

static void	ft_loop_hook(void *data)
{
	t_game	*game;
	bool	changed;

	game = (t_game *) data;
	changed = false;
	if (mlx_is_key_down(game->mlx, UP_KEY))
		changed |= ft_move_forward_backward(game, UP_KEY);
	if (mlx_is_key_down(game->mlx, DOWN_KEY))
		changed |= ft_move_forward_backward(game, DOWN_KEY);
	if (mlx_is_key_down(game->mlx, LEFT_KEY))
		changed |= ft_strafe(game, LEFT_KEY);
	if (mlx_is_key_down(game->mlx, RIGHT_KEY))
		changed |= ft_strafe(game, RIGHT_KEY);
	if (mlx_is_key_down(game->mlx, LEFT_ARROW_KEY))
		changed |= ft_rotate(game, LEFT_ARROW_KEY);
	if (mlx_is_key_down(game->mlx, RIGHT_ARROW_KEY))
		changed |= ft_rotate(game, RIGHT_ARROW_KEY);
	if (changed)
		ft_render(game);
}

void	ft_setup_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, ft_esc, game);
	mlx_loop_hook(game->mlx, ft_loop_hook, game);
	mlx_close_hook(game->mlx, ft_close, game);
}
