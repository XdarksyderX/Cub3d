/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:32:06 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:32:16 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
	mlx_delete_image(game->mlx, game->last_frame);
	i = 0;
	while (i < 4 && game->tex_loaded)
	{
		if (game->textures[i])
			mlx_delete_texture(game->textures[i]);
		i++;
	}
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
		exit(EXIT_FAILURE);
	}
	game->tex_loaded = true;
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
	player->x = (pos[1] * TILE_SIZE) + (TILE_SIZE / 2);
	player->y = (pos[0] * TILE_SIZE) + (TILE_SIZE / 2);
	if (pos[2] == 'N')
		player->angle = NORTH_ANGLE;
	else if (pos[2] == 'E')
		player->angle = EAST_ANGLE;
	else if (pos[2] == 'S')
		player->angle = SOUTH_ANGLE;
	else if (pos[2] == 'W')
		player->angle = WEST_ANGLE;
	free(pos);
	return (player);
}

static t_map	*ft_init_map(t_config *config)
{
	t_map	*map;

	if (!config || !config->map || !config->rows || !config->cols)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map || !config)
		return (free(map), NULL);
	map->width = config->cols;
	map->height = config->rows;
	map->map = (char **) ft_matrix_dup((void **)config->map);
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
	map_config = ft_get_config(config_file);
	if (!game)
		return (free(map_config), NULL);
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	game->tex_loaded = false;
	game->map = ft_init_map(map_config);
	if (!map_config || !ft_check_config(map_config) || !game->mlx || !game->map)
	{
		ft_free_game(game);
		ft_free_config(map_config);
		return (NULL);
	}
	game->ceiling_color = ft_get_color(map_config->ceiling_color);
	game->floor_color = ft_get_color(map_config->floor_color);
	ft_init_textures(game, map_config);
	ft_free_config(map_config);
	ft_setup_hooks(game);
	game->last_frame = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_render(game);
	return (game);
}
