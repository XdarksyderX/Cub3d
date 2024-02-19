/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:48 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Elimina y libera la memoria de todos los elementos de una lista enlazada.
 *
 * Esta función elimina y libera la memoria de todos los elementos de la lista
 * enlazada 'lst'. La función 'del' se utiliza para liberar la memoria de los
 * contenidos de los elementos.
 *
 * @param lst  La dirección del puntero al primer elemento de la lista.
 * @param del  La función utilizada para liberar la memoria de los contenidos de
 *             los elementos. Debe aceptar un puntero void * como argumento.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (*lst)
	{
		aux = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(aux);
	}
}
