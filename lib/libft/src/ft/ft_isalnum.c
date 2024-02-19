/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:02 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Verifica si un carácter es alfanumérico.
 *
 * Esta función verifica si el carácter 'c' es un carácter alfanumérico, es
 * decir, si es una letra (alfabética) o un dígito (numérico).
 *
 * @param c El carácter que se desea verificar.
 * @return 1 si 'c' es un carácter alfanumérico, 0 en caso contrario.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
