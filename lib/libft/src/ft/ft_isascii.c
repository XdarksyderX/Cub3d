/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:11 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Verifica si un valor entero representa un carácter ASCII válido.
 *
 * Esta función verifica si el valor entero 'c' representa un carácter ASCII
 * válido. Los caracteres ASCII válidos son aquellos con valores en el rango de
 * 0 a 127, inclusivo.
 *
 * @param c El valor entero que se desea verificar.
 * @return 1 si 'c' representa un carácter ASCII válido, 0 en caso contrario.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
