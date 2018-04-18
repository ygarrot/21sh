/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_comm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:23:54 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/17 12:26:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "21sh.h" 

int		skip_comm(char *str)
{
	int		i;
	char	q;

	i = 0;
	if (ft_isin(str[i], QUOTES) && (q = str[i++] == '"' ? '"' : '\''))
		while (str[i] && str[i++] != q)
			;
	return (i);
}
