/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:43 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copia un bloque de memoria desde una ubicación de origen a una ubicación de
 * destino, incluso si las áreas de origen y destino se superponen.
 *
 * Esta función copia 'size' bytes desde la ubicación de memoria 'src' a la
 * ubicación de memoria 'dest'. La copia se realiza de manera segura incluso si
 * las áreas de origen y destino se superponen. La función devuelve un puntero a
 * la ubicación de destino 'dest'.
 *
 * @param dest Puntero a la ubicación de destino donde se copiará el bloque de
 *             memoria.
 * @param src Puntero a la ubicación de origen desde donde se copiará el bloque
 *            de memoria.
 * @param size Número de bytes que se copiarán desde la ubicación de origen a la
 *             de destino.
 * @return Un puntero a la ubicación de destino 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		ft_memcpy(d, s, size);
	else
	{
		while (size--)
			d[size] = s[size];
	}
	return (d);
}
