/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:43 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Agrega un elemento al principio de una lista enlazada.
 *
 * Esta función agrega el elemento 'new' al principio de la lista enlazada
 * 'lst'. 'new' se convierte en el nuevo primer elemento de la lista y su 'next'
 * apunta al antiguo primer elemento.
 *
 * @param lst  La dirección del puntero al primer elemento de la lista.
 * @param new  El elemento que se desea agregar al principio de la lista.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
