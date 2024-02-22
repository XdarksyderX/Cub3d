/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:06 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 21:54:31 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parsing.h"

static void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		ft_free_map(game->map);
	free(game);
}

static void	ft_init_textures(t_game *game, t_config *config)
{
	game->textures[NORTH_TEXTURE] = mlx_load_png(config->north_texture_path);
	game->textures[SOUTH_TEXTURE] = mlx_load_png(config->south_texture_path);
	game->textures[EAST_TEXTURE] = mlx_load_png(config->east_texture_path);
	game->textures[WEST_TEXTURE] = mlx_load_png(config->west_texture_path);

	if (!game->textures[NORTH_TEXTURE] || !game->textures[SOUTH_TEXTURE]
		|| !game->textures[EAST_TEXTURE] || !game->textures[WEST_TEXTURE])
	{
		ft_free_game(game);
		ft_free_config(config);
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		exit(1);
	}
}

static t_player	*ft_init_player(t_config *config)
{
	t_player	*player;
	int			*pos;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	pos = ft_find_player_pos(config->map);
	if (!pos)
	{
		free(player);
		return (NULL);
	}
	player->x = pos[0];
	player->y = pos[1];
	if (pos[2] == 'N')
		player->angle = NORTH_ANGLE;
	else if (pos[2] == 'E')
		player->angle = EAST_ANGLE;
	else if (pos[2] == 'S')
		player->angle = SOUTH_ANGLE;
	else if (pos[2] == 'W')
		player->angle = WEST_ANGLE;
	return (player);
}

static t_map	*ft_init_map(t_config *config)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map || !config)
		return (free(map), NULL);
	map->width = config->cols;
	map->height = config->rows;
	map->map = ft_matrix_dup((void **)config->map);
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	map->player = ft_init_player(config);
	if (!map->player)
	{
		ft_free_map(map);
		return (NULL);
	}
	return (map);
}

t_game	*ft_init_game(char *config_file)
{
	t_game			*game;
	t_config		*map_config;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init(1920, 1080, "cub3d", true);
	map_config = ft_parse_map(config_file);
	game->map = ft_init_map(map_config);
	if (!game->mlx || !game->map)
	{
		ft_free_game(game);
		ft_free_config(map_config);
		return (NULL);
	}
	ft_init_textures(game, map_config);
	ft_free_config(map_config);
	return (game);
}