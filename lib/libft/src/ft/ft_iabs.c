/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:19:59 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calcula el valor absoluto de un número entero.
 *
 * Esta función toma un número entero 'nb' como entrada y devuelve su valor
 * absoluto, es decir, el número positivo equivalente al valor absoluto del
 * número original si 'nb' es negativo. Si 'nb' es positivo o cero, la función
 * simplemente devuelve 'nb' sin cambios.
 *
 * @param nb El número entero del que se calculará el valor absoluto.
 * @return El valor absoluto de 'nb' (si 'nb' es negativo) o 'nb'
 *         (si 'nb' es no negativo).
 */
int	ft_iabs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
