/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:05:39 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/11 13:54:29 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strrem(const char *s, size_t start, size_t len)
{
	char	*st;
	char	*st2;
	char	*s1;

	s1 = (char *)s;
	st = 0;
	if (start < ft_strlen(s))
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		st = ft_calloc(ft_strlen(s) - len + 1, sizeof(char));
		st2 = st;
		while (*s1)
		{
			if ((size_t)(s1 - s) < start || (size_t)(s1 - s) > start + len - 1)
			{
				st[st2 - st] = *s1;
				st2++;
			}
			s1++;
		}
	}
	else
		st = ft_calloc(1, sizeof(char));
	return (st);
}

static int	get_line(char **buffer, char **line, int bytes)
{
	char	*s;

	s = *buffer;
	if (!s)
		*line = ft_calloc(1, sizeof(char));
	else if (!ft_strchr(s, '\n'))
	{
		*line = ft_substr(s, 0, ft_strlen(s));
		free(s);
		*buffer = 0;
	}
	else
	{
		*line = ft_substr(s, 0, ft_strchr(s, '\n') - s);
		*buffer = ft_strrem(s, 0, ft_strchr(s, '\n') - s + 1);
		free(s);
		s = 0;
		bytes = 1;
	}
	return (bytes);
}

int	get_next_line(int fd, char **line)
{
	static char	*list[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line || BUFFER_SIZE < 1 )
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		if (!list[fd])
			list[fd] = ft_calloc(1, sizeof(char));
		tmp = list[fd];
		list[fd] = ft_strcat(tmp, buff);
		free(tmp);
		if (ft_strchr(list[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (ret == -1)
		return (-1);
	return (get_line(&list[fd], line, ret));
}
