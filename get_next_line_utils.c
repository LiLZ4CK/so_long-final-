/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:39:15 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/06 19:19:36 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

int	get_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	get_strchr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_strjoin(char *str, char *buf)
{
	char	*nwstr;
	int		a;
	int		i;
	int		j;

	a = 0;
	i = get_strlen(str);
	j = get_strlen(buf);
	nwstr = malloc(i + j + 1);
	while (a < i)
	{
		nwstr[a] = str[a];
		a++;
	}
	a = 0;
	while (a < j)
	{
		nwstr[i + a] = buf[a];
		a++;
	}
	free(str);
	nwstr[i + a] = '\0';
	return (nwstr);
}

char	*get_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(get_strlen(s1) + 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*get_substr(char const *s, size_t start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			t;

	i = 0;
	if (!s)
		return (NULL);
	t = get_strlen(s);
	if (len > t + 1)
		len = t + 1;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (len > 0 && start + i <= t && s[start + i])
	{
		str[i] = s[start + i];
		i++;
		len --;
	}
	str[i] = '\0';
	return (str);
}
