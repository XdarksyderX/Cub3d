/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:02:51 by zafraedu          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Libera la memoria asignada para un array de cadenas de caracteres y el propio
 * array.
 *
 * Esta función libera la memoria asignada para cada cadena de caracteres en el
 * array 'ptr', y luego libera la memoria utilizada por el propio array 'ptr'.
 * Finalmente, establece el puntero 'ptr' a NULL para evitar problemas de acceso
 * a memoria liberada.
 *
 * @param ptr Puntero al array de cadenas de caracteres.
 */
void	ft_free2d(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	ptr = NULL;
}
