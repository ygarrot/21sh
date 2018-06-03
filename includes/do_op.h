/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:51:54 by ygarrot           #+#    #+#             */
/*   Updated: 2018/06/03 16:52:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

typedef struct s_do_op 
{
    struct s_do_op *prev;
    struct s_do_op *next;
    char *content;
	bool	is_set;
	int		value;
	int		code;
}		t_do_op;


# define OPE (char *[16]){"<<", ">>", "||", "&&","**",  "|", "&", "^", "~", "+", "-", "/", "*", "%"}
# define OP_CREMENT (char *[3]){"--", "++"}

# define SHIFT (char *[3]){ "<<", ">>"}
# define COMP (char *[7]){"<=", ">=", "<", ">", "==", "!="}
# define HCOMP (char *[5]){ "<=", ">=", "<", ">"}
# define LCOMP (char *[3]){ "==", "!="}


/*
** math functions
*/
int	 parse_op(char *str);
char			**ft_custom_split(char *s, char **tb);
int (**f_opget(void))(int, int);
int		calc_op(char **op_tb);

int		is_local(char *str);
int		get_value(t_do_op *tmp);
int		do_op(t_do_op *a, t_do_op *op, t_do_op *b);
int		browse_last(t_do_op *list);
int		exec_op(char **tb);
int		bracket(char *str, char *brack);
/*
** bitwise
*/

int		ft_left_shift(int a, int b);
int		ft_right_shift(int a, int b);
int		ft_log_or(int a, int b);
int		ft_log_and(int a, int b);
int		ft_and(int a, int b);
int		ft_or(int a, int b);
int		ft_xor(int a, int b);
int		ft_bitneg(int a, int b);

/*
** classic op
*/

int		ft_mult(int a, int b);
int		ft_summ(int a, int b);
int		ft_div(int a, int b);
int		ft_sub(int a, int b);
int		ft_mod(int a, int b);

int		skip_char(char *str, char *to_skip);
int		ft_occiter2(char *str, int (*f)(int));

/*
** comp op
*/

int	ft_comp_infe(int a, int b);
int	ft_comp_supe(int a, int b);
int	ft_comp_inf(int a, int b);
int	ft_comp_sup(int a, int b);
int	ft_comp_neg(int a, int b);
int	ft_comp(int a, int b);

#endif