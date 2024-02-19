/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:37 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compara las primeras 'size' caracteres de dos cadenas de caracteres.
 *
 * Esta función compara los primeros 'size' caracteres de las str 's1' y 's2'.
 *
 * @param s1    La primera cadena de caracteres a comparar.
 * @param s2    La segunda cadena de caracteres a comparar.
 * @param size  El número máximo de caracteres a comparar.
 * @return      Un valor entero menor que, igual o mayor que cero, que indica si
 *              's1' es menor que, igual a o mayor que 's2', respectivamente.
 *              Devuelve un valor negativo si 's1' es menor que 's2'.
 *              Devuelve cero si 's1' es igual a 's2'.
 *              Devuelve un valor positivo si 's1' es mayor que 's2'.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (size--)
	{
		if (s1[i] != s2[i] || s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
