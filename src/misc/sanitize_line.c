/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:18:22 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:40:42 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"


static char	*remove_spaces_around_commas(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ',')
		{
			result[j++] = str[i++];
			while (str[i] && ft_isspace(str[i]))
				i++;
		}
		else if (ft_isspace(str[i]) && str[i + 1] == ',')
			i++;
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

static char	*remove_extra_spaces(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	while (str[i])
	{
		if (ft_isspace(str[i])
			&& (i == 0 || ft_isspace(str[i - 1]) || str[i + 1] == '\0'))
		{
			i++;
			continue ;
		}
		else
		{
			if (ft_isspace(str[i]))
				result[j++] = ' ';
			else
				result[j++] = str[i];
		}
		i++;
	}
	return (result[j] = '\0', result);
}

char	*ft_sanitize_line(char *str)
{
	char	*step1_str;
	char	*final_str;

	step1_str = remove_extra_spaces(str);
	if (!step1_str)
		return (NULL);
	final_str = remove_spaces_around_commas(step1_str);
	free(step1_str);
	return (final_str);
}
