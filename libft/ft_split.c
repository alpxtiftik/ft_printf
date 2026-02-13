/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:30:03 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/17 15:14:09 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**free_arr(char **sp, size_t i)
{
	while (i > 0)
	{
		i--;
		free(sp[i]);
	}
	free(sp);
	return (NULL);
}

static char	**fill(char **sp, char const *s, char c, size_t cw)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (i < cw)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		sp[i] = ft_substr(s, start, j - start);
		if (!sp[i])
			return (free_arr(sp, i));
		i++;
	}
	sp[i] = NULL;
	return (sp);
}

char	**ft_split(char const *s, char c)
{
	size_t	cw;
	char	**sp;

	if (!s)
		return (NULL);
	cw = count_words(s, c);
	sp = (char **) malloc(sizeof(char *) * (cw + 1));
	if (!sp)
		return (NULL);
	if (!fill(sp, s, c, cw))
		return (NULL);
	return (sp);
}
