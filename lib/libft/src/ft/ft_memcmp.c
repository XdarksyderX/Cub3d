/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:37 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compara dos regiones de memoria byte a byte.
 *
 * Esta función compara las primeras 'size' bytes de las regiones de memoria
 * 's1' y 's2' byte a byte. Devuelve un valor entero menor que, igual a, o
 * mayor que cero si 's1' es respectivamente menor o igual, o mayor que 's2'
 *
 * @param s1    Puntero a la primera región de memoria a comparar.
 * @param s2    Puntero a la segunda región de memoria a comparar.
 * @param size  Número de bytes a comparar.
 * @return      Un valor entero menor que, igual a, o mayor que cero si 's1' es
 *              respectivamente menor que, igual a o mayor que 's2'.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (size--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
