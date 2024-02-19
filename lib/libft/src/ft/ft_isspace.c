/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:22 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:52 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Comprueba si un carácter es un espacio en blanco.
 *
 * Esta función toma un valor entero que representa un carácter y determina
 * si es un espacio en blanco o no.
 *
 * @param c  El valor entero que se verificará como espacio en blanco.
 * @return   1 si 'c' es un espacio en blanco, 0 en caso contrario.
 */
int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
