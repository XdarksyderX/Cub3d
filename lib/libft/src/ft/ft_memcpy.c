/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:40 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copia 'size' bytes desde la memoria origen 'src' a la memoria destino 'dest'.
 *
 * Esta función copia 'size' bytes desde la memoria origen 'src' a la memoria
 * destino 'dest'. Si las regiones de memoria se superponen, el resultado es
 * indefinido, por lo que se debe evitar la superposición de las regiones de
 * memoria.
 *
 * @param dest  Puntero a la memoria destino donde se copiarán los datos.
 * @param src   Puntero a la memoria origen de donde se copiarán los datos.
 * @param size  Número de bytes a copiar.
 * @return      Puntero a la memoria destino 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (size--)
		*d++ = *s++;
	return (dest);
}
