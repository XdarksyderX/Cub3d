/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:18:52 by zafraedu          #+#    #+#             */
/*   Updated: 2024/02/25 12:57:56 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convierte una cadena de caracteres en un valor de tipo float/float.
 *
 * Esta función toma una cadena de caracteres que representa un número decimal
 * y la convierte en un valor de tipo float. Puede manejar números enteros y
 * decimales en formato estándar (por ejemplo, "123.45") o con coma decimal
 * (por ejemplo, "123,45").
 *
 * @param str La cadena de caracteres que se va a convertir a float.
 *
 * @return El valor float correspondiente a la cadena de caracteres.
 * Si la cadena no es un número válido, devuelve 0.0;
 */
float	ft_atof(char *str)
{
	int		num;
	float	rest;
	char	*tmp;
	int		i;

	num = ft_atoi(str);
	tmp = ft_strchr(str, '.');
	if (!tmp)
		tmp = ft_strchr(str, ',');
	if (!tmp)
		return (num);
	rest = ft_atoi(&tmp[1]);
	i = 1;
	while (tmp[i])
	{
		rest /= 10;
		i++;
	}
	if (num < 0 || (str[0] == '-' && str[1] == '0'))
		return (num - rest);
	return (num + rest);
}
