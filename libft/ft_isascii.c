/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:52:04 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/21 17:16:41 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Test a char to see if its a 7bit ASCII character.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
