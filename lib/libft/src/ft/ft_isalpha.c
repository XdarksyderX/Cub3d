/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:06 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Verifica si un carácter es una letra alfabética.
 *
 * Esta función verifica si el carácter 'c' es una letra alfabética (mayúscula o
 * minúscula). Se consideran letras alfabéticas a los caracteres que van desde
 * 'A' hasta 'Z' y desde 'a' hasta 'z'.
 *
 * @param c El carácter que se desea verificar.
 * @return 1 si 'c' es una letra alfabética, 0 en caso contrario.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
