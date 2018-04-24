/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:00:24 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/21 13:46:44 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define RESET "\x1b[0m"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/ioctl.h>

char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char *c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_memdel(void **ap);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnewc(void const *content, size_t content_size);
void			ft_lstdelone(t_list	**alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstpushfront(void *content, size_t content_size, t_list *b);
void			ft_lstpushback(t_list **left, t_list *right);
void			ft_lstfree(void *s, size_t t);
t_list			*ft_lstremoveif(t_list **begin, int (*cmp)(void *c, size_t t),
		void (*del)(void *, size_t));
t_list			*ft_lstreverse(t_list **begin);
t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));
t_list			*ft_lstat(t_list *begin, size_t t);
void			ft_lstvoid(void *content, size_t t);
size_t			ft_lstsize(t_list *lst);
char			*ft_lsttostr(t_list *lst);

char			*ft_capitalize(char *str);
char			*ft_itoamax(intmax_t nb);
char			*ft_uitoa_base_max(uintmax_t nb, char *base);
char			*ft_wchartostr(wchar_t *str);
char			*ft_strdupto(char *str, char to);
char			**ft_strtabdup(char **tabl);
char			*ft_itoabase(long int nb, char *base);
char			*ft_stradd(char *s1, char c);
size_t			ft_power(size_t nb, size_t pow);
int				ft_gotmod(size_t nb, int i);
int				ft_writenchar(char c, int n);
int				ft_strlenin(char *str, char *lim);
int				ft_strlento(char *str, char c);
int				ft_strlento_rev(char *str, int size, char *lim);
int				ft_strnocc(char *str, char c, int n);
int				ft_isin(char c, char *str);
int				ft_indexmin(int *tabl, size_t len);
int				ft_abs(int i);
int				ft_sqrt(int n);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_max(int n, int m);
int				ft_min(int n, int m);
int				ft_divideby(int nb, int div);
int				ft_insert(char **str, char *in, size_t to, size_t size);
int				ft_addtofd(char *str, int fd);
void			ft_strrev(char *str);
void			ft_replace(char *str, char c, char n);
void			*ft_realloc(void *ptr, size_t old, size_t size);

#endif