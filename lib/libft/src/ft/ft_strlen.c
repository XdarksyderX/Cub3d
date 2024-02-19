/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:28 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calcula la longitud de una cadena de caracteres.
 *
 * Esta función recibe una cadena de caracteres 'str' y devuelve la cantidad
 * de caracteres en la cadena, excluyendo el carácter nulo ('\0') al final.
 *
 * @param str  La cadena de caracteres cuya longitud se desea calcular.
 * @return     La cantidad de caracteres en la cadena 'str'.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
