/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:24:11 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/11 13:51:04 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

int		write_env(char **env)
{
	int	fd;
	int	i;

	i = -1;
	if ((fd = open(ft_getenvfile(CODE_ENVGET),
						O_RDWR | O_TRUNC | O_CREAT, S_IRWXU)))
		return (-1);
	while (env[++i])
	{
		ft_putstr_fd("\v", fd);
		ft_putstr_fd(env[i], fd);
	}
	return (close(fd));
}