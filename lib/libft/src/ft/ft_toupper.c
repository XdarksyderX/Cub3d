/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:56 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convierte un carácter en mayúsculas si es una letra minúscula.
 *
 * Esta función toma un carácter 'c' como argumento y, si 'c' es una letra
 * minúscula, la convierte en su equivalente en mayúsculas. Si 'c' no es
 * una letra minúscula, se devuelve sin cambios.
 *
 * @param c El carácter que se va a convertir a mayúsculas.
 * @return El carácter convertido o el mismo carácter si no es una letra
 *         minúscula.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
