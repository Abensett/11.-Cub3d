/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:26:39 by flee              #+#    #+#             */
/*   Updated: 2021/06/27 09:45:32 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 99999

//------------------------GNL-------------------------------------//

int		ft_strlen_gnl(const char *str, int state);
size_t	ft_strlcpy_gnl(char *dest, const char *src, unsigned int size);
char	*ft_strjoin_gnl(char *s1, char const *s2, int read_return);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int state);
int		ft_check_gnl(char *memory);
char	*ft_fill_memory_gnl(char *memory, char buf[BUFFER_SIZE + 1], int fd);
char	*get_next_line(int fd);


//-----------------------------------------------------------------//

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *d, const void *s,
					int c, size_t si);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memchr(const void *memoryBlock, int searchedChar,
					size_t size);
int				ft_memcmp(const void *pointer1, const void *pointer2,
					size_t size);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int character);
int				ft_isdigit(int character);
int				ft_isalnum(int character);
int				ft_isascii(int character);
int				ft_isprint(int character);
int				ft_toupper(int character);
int				ft_tolower(int character);
char			*ft_strchr(const char *hay, int needle);
char			*ft_strrchr(const char *hay, int needle);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t			ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t elementCount, size_t elementSize);
char			*ft_strdup(char *src);
char			*ft_substr(char const *src, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char sep);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_size(char **tab);
char			**ft_popTab(char **tab, int i);

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_free_tab(char **str);

#endif
