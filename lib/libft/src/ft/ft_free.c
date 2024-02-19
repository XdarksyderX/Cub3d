/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:03:06 by zafraedu          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Libera la memoria asignada a un puntero y establece el puntero a NULL.
 *
 * Esta función libera la memoria asignada al puntero 'ptr' utilizando la
 * función 'free', y luego establece el puntero 'ptr' a NULL para evitar
 * problemas de acceso a memoria liberada.
 *
 * @param ptr   Puntero cuya memoria se va a liberar y establecer a NULL.
 */
void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}
