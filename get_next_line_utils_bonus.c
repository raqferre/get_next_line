/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:51:15 by raqferre          #+#    #+#             */
/*   Updated: 2022/07/22 19:17:06 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)

{
	void	*rtr;

	if (nmemb == 0 | size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	rtr = malloc (nmemb * size);
	if (!rtr)
		return (NULL);
	if (rtr)
		ft_bzero (rtr, nmemb * size);
	return (rtr);
}

void	ft_bzero(void *s,	size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *) s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		n;

	if (!s1)
		s1 = ft_calloc (1, 1);
	if (!s1 || !s2)
		return (NULL);
	newstring = ft_calloc (1, (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!newstring)
		return (0);
	i = -1;
	n = 0;
	if (s1)
		while (s1[++i] != '\0')
				newstring[i] = s1[i];
	while (s2[n] != '\0')
		newstring[i++] = s2[n++];
	newstring[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (newstring);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
	++x;
	return (x);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
			i++;
	}		
	return (0);
}
