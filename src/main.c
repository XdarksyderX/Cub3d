/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:56:02 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/22 20:38:17 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "MLX42.h"

int	main(int argc, char **argv)
{
	t_map_config	*data;
	if (argc != 2)
	{
		ft_usage();
		return (1);
	}
	data = ft_get_config(argv[1]);
	ft_debug_config(data);
}
