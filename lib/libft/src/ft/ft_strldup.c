/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:24 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplica una subcadena de una cadena dada.
 *
 * Esta función crea una nueva cadena terminada en nulo duplicando una subcadena
 * específica de la cadena de entrada. Si 'len' es menor que la longitud real de
 * la cadena de entrada, solo se copiarán los primeros 'len' caracteres.
 * Si 'len' es mayor o igual a la longitud real, se duplicará toda la cadena de
 * entrada.
 *
 * @param str La cadena de entrada a duplicar.
 * @param len La longitud de la subcadena a copiar.
 * @return Un puntero a la cadena duplicada,
 *	o NULL si falla la assignación de memoria
 */
char	*ft_strldup(const char *str, size_t len)
{
	size_t	actual_len;
	size_t	copy_len;
	char	*new_str;

	if (str == NULL)
		return (NULL);
	actual_len = ft_strlen(str);
	if (len < actual_len)
		copy_len = len;
	else
		copy_len = actual_len;
	new_str = (char *)malloc(copy_len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, str, copy_len);
	new_str[copy_len] = '\0';
	return (new_str);
}
