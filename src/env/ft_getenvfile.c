/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenvfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:31:11 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 13:49:15 by tcharrie         ###   ########.fr       */
/*   Updated: 2018/05/11 13:07:10 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_getenvfile(int code)
{
	static char		*str = 0;
	char			*tmp;

	if (!ENVFILE)
		return (0);
	if (!str)
		str = ft_strdup(ENVFILE);
	if (code == CODE_ENVADD)
	{
		if (!(tmp = ft_memalloc(ft_strlen(str) + 2)))
			return (0);
		ft_strcat(tmp, str);
		tmp[ft_strlen(str)] = '0';
		ft_cpy(str, tmp);
		free(str);
		str = tmp;
	}
	else if (code == CODE_ENVGET)
	{
		if (ft_strlen(str) < ft_strlen(ENVFILE))
			return (0);
	}
	return (ft_strdup(str));
}