/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:05:54 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/11 13:54:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	char	*pbuff;

	if (!str)
		return (0);
	pbuff = (char *)str;
	while (*pbuff)
		pbuff++;
	return (pbuff - str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*sd;

	sd = (char *)s;
	while (*sd)
	{
		if (*sd == (char)c)
			return (sd);
		sd++;
	}
	return (0);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*st;
	char	*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	st = ft_calloc(len + 1, sizeof(char));
	if (st)
	{
		while (len > 0)
		{
			st[len - 1] = s1[start + len - 1];
			len--;
		}
		return (st);
	}
	return (0);
}

char	*ft_strcat(const char *s1, const char *s2)
{
	char	*ret;
	char	*ps1;
	char	*ps2;

	if (s1 && s2)
	{
		ps1 = (char *)s1;
		ps2 = (char *)s2;
		ret = ft_calloc(ft_strlen(ps1) + ft_strlen(ps2) + 1, sizeof(char));
		if (ret)
		{
			while (*ps1)
			{
				ret[ps1 - s1] = *ps1;
				ps1++;
			}
			while (*ps2)
			{
				ret[(ps1 - s1) + (ps2 - s2)] = *ps2;
				ps2++;
			}
			return (ret);
		}
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	size *= count;
	ret = malloc(size);
	if (!ret)
		return (0);
	while (size > 0)
		ret[--size] = 0;
	return (ret);
}
