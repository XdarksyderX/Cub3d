/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:12 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplica una cadena de caracteres.
 *
 * Esta función toma como entrada una cadena de caracteres 'str' y crea una
 * copia de esa cadena en un nuevo bloque de memoria dinámica. La función
 * devuelve un puntero a la copia de la cadena, o NULL si no se pudo asignar
 * memoria para la copia.
 *
 * @param str  La cadena de caracteres que se desea duplicar.
 *
 * @return     Un puntero a la copia de la cadena, o NULL en caso de error.
 */
char	*ft_strdup(const char *str)
{
	int		len;
	char	*copy;

	len = ft_strlen(str);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (len >= 0)
	{
		copy[len] = str[len];
		len--;
	}
	return (copy);
}
