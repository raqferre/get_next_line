/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:12:45 by raqferre          #+#    #+#             */
/*   Updated: 2022/07/22 17:54:08 by raqferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_line(int fd, char *temp)
{
	char	*buf;
	int		byte;

	buf = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	byte = 1;
	while (!ft_strchr(temp, '\n') && byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{	
			free(buf);
			return (NULL);
		}
		buf[byte] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*line(char *temp)
{
	char	*out;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
			i++;
	out = (char *) malloc (sizeof(char) * (i + 2));
	if (!out)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		out[i] = temp[i];
		i++;
	}	
	if (temp[i] == '\n')
	{
		out[i] = temp [i];
		i++;
	}			
	out[i] = '\0';
	return (out);
}	

char	*leftover(char *save)
{
	char	*out;
	int		i;
	int		n;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}		
	out = (char *) malloc (ft_strlen(save) - i + 1);
	if (!out)
		return (NULL);
	i++;
	n = 0;
	while (save[i])
	{
		out[n++] = save[i++];
	}	
	out[n] = '\0';
	free(save);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line (fd, temp);
	if (!temp)
		return (NULL);
	out = line (temp);
	temp = leftover (temp);
	return (out);
}
