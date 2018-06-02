/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variable_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:28:08 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/02 12:25:27 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_variable	*ft_variable_create(char *name, void *data, int deep, int deported)
{
	t_variable	*el;

	if (!(el = (t_variable*)malloc(sizeof(t_variable))))
		return (0);
	el->name = name;
	el->deep = deep;
	el->deported = deported;
	if (el->deep == 1)
	{
		el->str = (char*)data;
		el->array = 0;
	}
	else if (el->deep == 2)
	{
		el->str = 0;
		el->array = (char**)data;
	}
	return (el);
}

void		ft_variable_builtin(char *str)
{
	char		*setenv[4];
	int			i;
	char		***env;
	int			deported;

	i = ft_strlento('=', str);
	if (!str[i] || i == 0)
		return ;
	deported = 0;
	str[i] = 0;
	if (!ft_variable_checkname(str))
		return ;
	if (ft_getenv_fromroot(str))
	{
		if ((env = ft_storeenv(0)))
		{
			deported = 1;
			setenv = {"setenv", str, &str[i + 1], 0};
			ft_setenv(arg, env);
		}
	}
	ft_variableadd(str, (void*)&str[i + 1], 1, deported);
	str[i] = '=';
}

int			ft_variable_checkname(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isin(str[i++], VAR_LIM))
			return (0);
	}
	return (1);
}
