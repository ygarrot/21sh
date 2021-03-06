/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:57:20 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/16 13:50:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (0);
	return (nb * ft_power(nb, pow - 1));
}
