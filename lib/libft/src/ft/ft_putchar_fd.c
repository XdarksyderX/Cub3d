/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:21:50 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/19 21:47:46 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Escribe un carácter en un descriptor de archivo específico.
 *
 * Esta función toma un carácter 'c' y lo escribe en el descriptor de archivo
 * 'fd'.
 *
 * @param c     El carácter que se escribirá en el archivo.
 * @param fd    El descriptor de archivo donde se escribirá el carácter.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
