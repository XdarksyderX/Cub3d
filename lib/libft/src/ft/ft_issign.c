/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:22 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Verifica si un valor entero representa un signo (+ o -).
 *
 * Esta función verifica si el valor entero 'c' representa un signo, ya sea
 * positivo (+) o negativo (-). Los valores 43 y 45 corresponden a los códigos
 * ASCII de los signos '+' y '-' respectivamente.
 *
 * @param c El valor entero que se desea verificar.
 * @return 1 si 'c' representa un signo (+ o -), 0 en caso contrario.
 */
int	ft_issign(int c)
{
	return (c == 43 || c == 45);
}
