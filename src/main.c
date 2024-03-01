/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:56:02 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/01 23:08:12 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !ft_have_extension(argv[1], ".cub"))
	{
		ft_usage();
		return (EXIT_FAILURE);
	}
	if (!ft_file_exists(argv[1]))
	{
		ft_putstr_fd("Error\nFile not found\n", 2);
		return (EXIT_FAILURE);
	}
	game = ft_init_game(argv[1]);
	if (!game)
		return (EXIT_FAILURE);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
