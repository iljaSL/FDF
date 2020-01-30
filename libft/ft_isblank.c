/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:25:32 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/21 17:16:48 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Checks if the passed char is blank or not.
*/

int	ft_isblank(int c)
{
	return (c == '\t' || c == ' ');
}
