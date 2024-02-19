/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:06 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Busca la primera ocurrencia de un carácter en una cadena de caracteres.
 *
 * Esta función busca la primera aparición del carácter 'c' en la cadena 'str' y
 * devuelve un puntero al primer carácter coincidente en 'str' o NULL si 'c' no
 * se encuentra en la cadena.
 *
 * @param str  La cadena de caracteres en la que se buscará 'c'.
 * @param c    El carácter que se desea encontrar en 'str'.
 *
 * @return Un puntero al primer carácter coincidente en 'str' o NULL si 'c' no
 *         se encuentra en la cadena.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!(*str))
			return (NULL);
		str++;
	}
	return ((char *)str);
}
