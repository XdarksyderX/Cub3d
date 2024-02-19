/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:22:50 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convierte un carácter en mayúscula en su equivalente en minúscula.
 *
 * Si el carácter 'c' es una letra mayúscula (A-Z), esta función lo convierte
 * en su equivalente en minúscula y lo devuelve. Si 'c' no es una letra
 * mayúscula, se devuelve sin cambios.
 *
 * @param c  El carácter que se va a convertir en minúscula.
 * @return (El carácter 'c' convertido en minúscula, si es una letra mayúscula);
 *         de lo contrario, se devuelve sin cambios.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
