/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:56:02 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/24 21:49:08 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_usage();
		return (1);
	}
	game = ft_init_game(argv[1]);
	if (!game)
	{
		ft_putstr_fd("Error\nFailed to initialize game\n", 2);
		return (1);
	}
	ft_render(game);
	mlx_loop(game->mlx);
}

