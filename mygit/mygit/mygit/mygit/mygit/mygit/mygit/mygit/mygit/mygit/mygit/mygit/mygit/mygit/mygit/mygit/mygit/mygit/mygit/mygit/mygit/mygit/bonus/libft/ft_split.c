/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:03:56 by flee              #+#    #+#             */
/*   Updated: 2021/06/27 09:47:44 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeof_word(char const *str, char sep)
{
	int		size;

	size = 0;
	while (str[size] != '\0' && str[size] != sep)
		size++;
	return (size);
}

int	ft_count_word(char const *str, char sep)
{
	int	words;
	int	state;
	int	index;

	words = 0;
	state = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == sep)
			state = 1;
		else
		{
			if (state == 1)
				words++;
			state = 0;
		}
		index++;
	}
	return (words);
}

int	ft_tabcreation(int words, char const *str,
		char sep, char **memorytab)
{
	int	i;
	int	index;
	int	cmpt;

	cmpt = 0;
	index = 0;
	while (index < words)
	{
		while (str[cmpt] != '\0' && str[cmpt] == sep)
			cmpt++;
		memorytab[index] = (char *)malloc(sizeof(char)
				* ((ft_sizeof_word(&str[cmpt], sep) + 1)));
		if (!memorytab)
			return (1);
		i = 0;
		while (str[cmpt] != '\0' && str[cmpt] != sep)
		{
			memorytab[index][i++] = str[cmpt];
			cmpt++;
		}
		memorytab[index][i] = '\0';
		index++;
	}
	memorytab[index] = NULL;
	return (0);
}

char	**ft_split(char const *str, char sep)
{
	int		words;
	char	**memorytab;

	if (str)
	{
		words = ft_count_word(str, sep);
		memorytab = (char **)malloc(sizeof(char *) * (words + 1));
		if (!memorytab)
			return (NULL);
		if (ft_tabcreation(words, str, sep, memorytab))
			return (NULL);
		return (memorytab);
	}
	return (NULL);
}
