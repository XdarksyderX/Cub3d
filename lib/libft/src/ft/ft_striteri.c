/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:15 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Aplica una función a cada caracter de una cadena con índice.
 *
 * Esta función toma como entrada un String 's' y una función 'f'. Itera a
 * través de cada caracter en la cadena y llama a la función 'f' pasando el
 * índice del caracter y el propio caracter como argumentos. Esto permite
 * modificar o procesar cada caracter individualmente en la cadena.
 *
 * @param s  La cadena de caracteres a la que se aplicará la función.
 * @param f  La función que se aplicará a cada caracter.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = ft_strlen(s);
	while (i--)
		f(i, &s[i]);
}
