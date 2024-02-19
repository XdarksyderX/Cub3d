/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:55 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:52 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Aplica una función a cada elemento de una lista enlazada.
 *
 * Esta función recorre la lista enlazada 'lst' y aplica la función 'f' a cada
 * elemento de la lista.
 *
 * @param lst  El primer elemento de la lista enlazada.
 * @param f    La función que se aplicará a cada elemento de la lista.
 *             Debe aceptar un puntero void * como argumento.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
