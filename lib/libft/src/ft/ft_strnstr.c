/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:39 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Busca la primera aparición de una subcadena en una cadena, limitando la
 * búsqueda a los primeros 'size' caracteres de la cadena principal.
 *
 * Esta función busca la primera aparición de la subcadena 'needle' en la cadena
 * 'haystack', pero limitando la búsqueda a los primeros 'size' caracteres de
 * 'haystack'.
 *
 * @param haystack La cadena principal en la que se busca la subcadena.
 * @param needle La subcadena que se busca en 'haystack'.
 * @param size El número máximo de caracteres de 'haystack' a considerar.
 * @return Un puntero al primer carácter de la primera aparición de 'needle' en
 * 'haystack', o NULL si no se encuentra 'needle' en 'haystack' o si 'needle' es
 * una cadena vacía.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;

	i = ft_strlen(needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && size-- >= i)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, i) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
