/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:11:18 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/30 13:22:49 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			b;
	char			*str;

	i = 0;
	b = c;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == b)
			return (&str[i + 1]);
		i++;
	}
	if (str[i] == '\0' && b == '\0')
		return (str + i);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!(s2))
		return (NULL);
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char				*res;
	unsigned long int	i;
	size_t				len1;
	size_t				len2;

	if (s1 == NULL)
		return (s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	if (s1 != 0 && s2 != 0)
	{
		res = malloc(sizeof(char) * (len1 + len2 + 1));
		if (!res)
			return (NULL);
		while (++i < len1)
			res[i] = s1[i];
		i--;
		while (++i < len1 + len2)
			res[i] = s2[i - len1];
		res[i] = '\0';
		free(s1);
		return (res);
	}
	return (NULL);
}
