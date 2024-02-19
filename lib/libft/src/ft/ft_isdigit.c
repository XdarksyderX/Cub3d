/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:22 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Verifica si un valor entero representa un dígito decimal.
 *
 * Esta función verifica si el valor entero 'c' representa un dígito decimal,
 * es decir, un número del 0 al 9.
 *
 * @param c El valor entero que se desea verificar.
 * @return 1 si 'c' representa un dígito decimal, 0 en caso contrario.
 */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
