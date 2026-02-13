/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtiftik <ahtiftik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:28:09 by ahtiftik          #+#    #+#             */
/*   Updated: 2026/01/17 14:20:59 by ahtiftik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		i;
	char		*ns;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ns = (char *) malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	while (i < len)
	{
		ns[i] = f((unsigned int)i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
