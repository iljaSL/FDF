/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:27:06 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/21 17:19:42 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Duplicates the string at most size bytes that given size in the function.
** It also returns a pointer to null-terminated byte string.
*/

char	*ft_strndup(const char *str, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	if (!(result = ft_strnew(len)))
	{
		return (NULL);
	}
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
