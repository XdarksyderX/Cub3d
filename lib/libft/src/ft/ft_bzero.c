/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:19:54 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Rellena con 0 los primeros `size` bytes de la memoria apuntada por `str`.
 *
 * Esta función se utiliza para inicializar una región de memoria a cero (0).
 * Toma un puntero a una región de memoria y un tamaño 'size' y establece a cero
 * los primeros 'size' bytes de esa región de memoria.
 *
 * @param str  Puntero a la región de memoria que se va a inicializar a cero.
 *
 * @param size Tamaño en bytes de la región de memoria que se inicializará a 0.
 */
void	ft_bzero(void *str, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < size)
		s[i++] = 0;
}
