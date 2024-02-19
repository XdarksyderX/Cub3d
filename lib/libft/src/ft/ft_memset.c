/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:45 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Llena un bloque de memoria con un valor constante.
 *
 * Esta función establece los primeros 'size' bytes del bloque de memoria
 * apuntado por 'str' con el valor especificado por 'c'. Es comúnmente utilizada
 * para inicializar una región de memoria con un valor constante, como llenar u
 * arreglo con ceros o algún otro valor.
 *
 * @param str    Puntero al bloque de memoria que se llenará.
 * @param c      Valor que se utilizará para llenar el bloque de memoria.
 * @param size   Número de bytes que se llenarán con el valor 'c'.
 * @return       Un puntero al bloque de memoria 'str' después de llenarlo.
 */
void	*ft_memset(void *str, int c, size_t size)
{
	size_t	i;
	char	*pstr;

	i = 0;
	pstr = (char *)str;
	while (i < size)
		pstr[i++] = c;
	return (str);
}
