/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:23 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:52 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Crea un nuevo elemento de lista con el contenido especificado.
 *
 * Esta función crea un nuevo elemento de lista con el contenido 'content' y lo
 * devuelve como un puntero a la nueva lista.
 *
 * @param content El contenido que se almacenará en el nuevo elemento.
 * @return Un puntero al nuevo elemento de la lista o NULL en caso de error.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
