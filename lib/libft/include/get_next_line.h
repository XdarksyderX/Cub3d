/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:08:05 by zafraedu          #+#    #+#             */
/*   Updated: 2024/02/19 21:38:00 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*════════════════════════════ [  LIBS ] ═════════════════════════════════════*/
# include "./libft.h"
# include <stddef.h>

/*════════════════════════════ [  MACROS ] ═══════════════════════════════════*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*═════════════════════════ [  FUNCTIONS ] ═══════════════════════════════════*/

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
