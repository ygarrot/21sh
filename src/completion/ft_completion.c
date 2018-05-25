/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_completion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:56:06 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/25 12:30:48 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_completion_(t_line *line, int *val, char *left, int type)
{
	char	*right;
	int		bl;
	int		sep;
	int		re;
	int		bq;

	ft_errorlog(type == COMPLETION_FILE ? "FILE" : type == COMPLETION_COM ? "COM" : "TRASH");
	ft_completion_count(CODE_PUSH);
	if (val[4])
		bq = ft_separator_active(&(line->line)[val[0] - (int)ft_strlen(left)],
			(int)ft_strlen(left), &sep, &bl);
	else
		bq = ft_separator_active(&(line->eof)[val[0] - (int)ft_strlen(left)],
			(int)ft_strlen(left), &sep, &bl);
	right = (type == COMPLETION_FILE) ? (ft_completion_getfilename(left,
		ft_completion_count(CODE_GET), bl, sep)) : ft_completion_com(left,
		ft_completion_count(CODE_GET), bl, sep);
	ft_strdel(&left);
	ft_errorlog("No right");
	if (!right)
		return (ft_completion_reset() ? -1 : -1);
	re = (ft_printstr(line, right, val) < 0) ? (-1) : (0);
	ft_completion_lastwrite(CODE_SET, re ? 0 : ft_strlen(right));
	ft_strdel(&right);
	return (re);
}

int		ft_completion(t_line *line, int *val)
{
	char	*leftpurged;
	char	*left;
	int		type;

	if (ft_completion_count(CODE_GET) > 0)
	{
		if (ft_nerase(line, val, ft_completion_lastwrite(CODE_GET, 0)) < 0)
			return (-1);
	}
	if (!(type = ft_completion_type(line, val)))
	{
		ft_completion_reset();
		return (0);
	}
	if (!(left = ft_completion_start(line, val)))
		return (ft_completion_reset() ? -1 : -1);
	leftpurged = ft_strpurgesep(left);
	ft_strdel(&left);
	if (!leftpurged)
		return (ft_completion_reset() ? -1 : -1);
	return (ft_completion_(line, val, leftpurged, ft_completion_type(line, val)));
}
