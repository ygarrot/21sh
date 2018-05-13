/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:43:37 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/12 16:40:00 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*ft_completion_startcpy(char *str, char *tmp, int from, int to)
{
	int	sep[2];
	int	j;
	int	k;

	j = 0;
	ft_bzero((void*)sep, sizeof(sep));
	while (from < to)
	{
		if ((tmp[from] == '\n' && !sep[0] && sep[1]) ||
	(tmp[from] == '\'' && (sep[0] == '\'' || (!sep[1] && !sep[0]))) ||
	(tmp[from] == '\"' && (sep[0] != '\'' && !sep[1])) ||
	(tmp[from] == '\\' && (!sep[1] && sep[0] != '\'')))
		{
			sep[0] = ft_separator(tmp[from], sep[0], sep[1]);
			sep[1] = tmp[from++] == '\\' && !sep[1] && sep[0] != '\'';
		}
		else if ((k = ft_lenchar_r(tmp, from)) > 0)
		{
			sep[0] = ft_separator(tmp[from], sep[0], sep[1]);
			sep[1] = !sep[1] && sep[0] != '\'' && tmp[from] == '\\';
			while (k-- > 0)
				str[j++] = tmp[from++];
		}
	}
	return (str);
}

char		*ft_completion_start(t_line *line, int *val)
{
	char	*str;
	int		i;
	char	*tmp;

	if (!line || !(tmp = val[4] ? line->line : line->eof))
		return (0);
	if (val[0] <= val[5] || ft_isin(line->line[val[0] - 1], " \n;|&<>"))
		i = 0;
	else
		i = ft_lennchar_l(tmp, val[0], ft_lenword_l(tmp, val[0]));
	printf("%d\n", i);
	if (!(str = (char*)ft_memalloc(i + 1)))
		return (0);
	i = val[0] - i;
	return (ft_completion_startcpy(str, tmp, i, val[0]));
}