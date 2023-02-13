/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:49:42 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/10 12:13:38 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*get_line(char *str, char *tmp)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = 0;
	if (!tmp[len])
		return (NULL);
	while (tmp[len] && tmp[len] != '\n')
		len++;
	len += (tmp[len] == '\n');
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (i < len)
		line[i++] = *tmp++;
	while (*tmp)
	{
		str[i - len] = *tmp++;
		i++;
	}
	str[i - len] = '\0';
	return (line);
}

char	*get_line_store(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (j < i)
		line[j++] = *str++;
	while (*str)
	{
		*(str - i) = *str;
		str++;
	}
	*(str - i) = '\0';
	return (line);
}

char	*get_str(int fd, char *str)
{
	ssize_t	nbyte;
	char	*buf;
	char	*tmp;

	nbyte = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!tmp || !buf)
		return (NULL);
	ft_memcpy(tmp, str, ft_strlen(str) + 1);
	while (nbyte > 0 && !ft_strchr(tmp, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte <= 0)
		{
			free(buf);
			if (tmp[0] != '\0')
				return (tmp);
			return (free(tmp), NULL);
		}
		buf[nbyte] = '\0';
		tmp = ft_free_strjoin(tmp, buf);
	}
	return (free(buf), tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	store[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(store, '\n'))
		line = get_line_store(store);
	else
	{
		tmp = get_str(fd, store);
		if (!tmp || (!tmp[0] && !store[0]))
		{
			free(tmp);
			return (NULL);
		}
		line = get_line(store, tmp);
		free(tmp);
	}
	return (line);
}
