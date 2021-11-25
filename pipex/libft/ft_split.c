/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:01:36 by                   #+#    #+#             */
/*   Updated: 2021/10/10 09:59:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_word(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
	}
	return (word);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

void	*leak(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**fill_str(char const *s, char c, char **res, int word)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	while (++i < word)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		res[i] = malloc(len + 1);
		if (!res[i])
			return (leak(res, i));
		j = 0;
		while (j < len)
			res[i][j++] = *s++;
		res[i][j] = '\0';
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word;

	if (!s)
		return (0);
	word = ft_word(s, c);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (0);
	res = fill_str(s, c, res, word);
	return (res);
}
