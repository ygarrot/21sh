/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:06:05 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/18 15:07:47 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define OP_COMP "== != <= >= < >"
#define OP_ASSIGN "= *= /= %= += -= <<= >>= &= ^= |="

//#define OP_BIT "<< >> | || && & ^ ~"
#define ALL_OP "*= /= %= += -= <<= >>= &= ^= |=  == != <= >= -- ++ << >> || | ** && & ^ ~ < > = * / - +"

# define BIT (char *[14]){"<<", ">>", "|", "||", "&&", "&", "^", "~"}

# define OPE (char *[14]){"<<", ">>", "||", "&&","**",  "|", "&", "^", "~", "+", "-", "/", "*", "%"}
# define COMP (char *[14]){ "==", "!=", "<=", ">=", "<", ">"}
# define ASSIGN (char *[14]){"*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=", "|=", "="}

	
#include "../../includes/sh.h"

int		is_legal(char c)
{
	if (!ft_isalnum(c))
		return (0);
	return (1);
}

#define A 0
#define O 1
#define B 2
#define RES 3
int		is_local(char *str)
{
	if (1)
		return (1);
	else if (2)
		return (0);
}

int	 parse_op(char *str)
{
	char	**op_tb;
	int			tab_len;
	int		res;

	op_tb = ft_custom_split(str, ft_strsplit(ALL_OP, ' '));
	tab_len = ft_tablen(op_tb) -1;
	while (tab_len > -1 && ft_strisin_tab(op_tb[tab_len], ASSIGN, 0) < 0)
		tab_len--;
	if (tab_len >= 0 && ft_occiter2(op_tb[tab_len - 1], ft_isdigit) >= 0)
		exit(-ft_printf("bad math expression: operand expected at %s", op_tb[tab_len]));
	res = calc_op(op_tb);
	return (res);
}

int	main()
{
	parse_op("1 + 1");
}
