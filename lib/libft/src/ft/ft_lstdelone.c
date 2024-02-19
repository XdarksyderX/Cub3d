/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:20:51 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Elimina y libera la memoria de un solo elemento de una lista enlazada.
 *
 * Esta función elimina y libera la memoria de un solo elemento de la lista
 * enlazada 'lst'. La función 'del' se utiliza para liberar la memoria de su
 * contenido.
 *
 * @param lst  El elemento que se desea eliminar y liberar.
 * @param del  La función utilizada para liberar la memoria de los contenidos
 *             del elemento. Debe aceptar un puntero void * como argumento.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
