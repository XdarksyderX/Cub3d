/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:09 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compara dos cadenas de caracteres (strings) y devuelve un valor que indica su
 * orden lexicográfico.
 *
 * @param s1 - La primera cadena de caracteres a comparar.
 * @param s2 - La segunda cadena de caracteres a comparar.
 * @return 0 si las cadenas son iguales, un número negativo si s1 es menor que
 *         s2, o un número positivo si s1 es mayor que s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
