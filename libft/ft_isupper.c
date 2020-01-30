/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:36:02 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/21 17:17:14 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Checks whether the passed char is uppercase letter.
*/

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
