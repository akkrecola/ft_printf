/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:00:26 by elehtora          #+#    #+#             */
/*   Updated: 2022/09/24 19:44:16 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Necessary (and permitted) inclusions */
# include <string.h>
# include <stdint.h>

/* Linked list typedef */
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/* Part 1 function prototypes */
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memrchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_charappend(char *str, char append);
size_t		ft_strlen(const char *s);
size_t		ft_strdlen(const char *s, const char delim);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strddup(const char *s, char d);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdcpy(char *dst, const char *src, char d);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrev(const char *str);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strpbrk(const char *s, const char *charset);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_iswhite(int c);
char		ft_arechars(const char *str, const char *charset);

/* Part 2 function prototypes */
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_strrclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strmodify(char const *initial, char *(*f)(char const *));
char		*ft_strgetset(char const *s, char *tset, char *dset, size_t maxlen);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdjoin(char const *head, char const *delim, char const *tail);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
size_t		ft_strspn(const char *s, const char *charset);
char		*ft_itoa(int n);
char		*ft_ltoa_unsigned(unsigned long long n);
char		*ft_ltoa(long long n);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putbits(void *var, uint8_t bytes);

/* Math */
double		ft_pow(double base, double exp);
long double	ft_powl(long double base, long double exp);
float		ft_powf(float base, float exp);
int			ft_powi(int base, int exp);
int			ft_abs(int x);
long		ft_labs(long x);
long long	ft_llabs(long long x);
double		ft_fabs(double x);
long double	ft_lfabs(long double x);
long double	ft_truncl(long double x);
long double	ft_roundl(long double x);

/* Bonus part function prototypes */
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/* Mandatory helper function for list testing */
void		ft_del(void *content, size_t content_size);

/* Voluntary functions (for testing) */
size_t		ft_count_digs(int n);
void		ft_putmem(char *s, size_t n);
t_list		*ft_lstcpyone(t_list *link);

/* Additional functions added after completion */
char		*ft_strsep(char **p_string, int c);
size_t		ft_nat_sqrt(unsigned int n);

#endif
