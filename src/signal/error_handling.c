/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:51:31 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/12 13:10:14 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sh.h"

void	mallcheck(void *foo)
{
	if (!foo)
		exit(EXIT_FAILURE);
}

void	parse_exe(t_shell *sh, char *comm, char **arg)
{
	int	index;

	if (exec_redi(sh, sh->tmp->redi) < 0)
		exit(error_exec(arg));
	if (!ft_strcmp(comm, "env"))
		ft_env(sh, arg, &sh->env);
	else if ((index = ft_strisin_tab(arg[0], BUILT, 0)) >= 0)
		sh->f_built[index](arg, &sh->env);
	else if (execve(comm, arg, sh->env))
		exit(error_exec(arg));
}

int		error_exec(char **argv)
{
	ft_printf("Command not found %s\n", *argv);
	return (-1);
}
