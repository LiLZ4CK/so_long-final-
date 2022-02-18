/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:37:33 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/10 02:17:19 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*l;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		l = get_substr(str, 0, i + 1);
		return (l);
	}
	l = get_strdup(str);
	return (l);
}

char	*get_next(char *str)
{
	int		i;
	char	*sstr;

	i = 0;
	sstr = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		i++;
		sstr = get_substr(str, i, get_strlen(str) - i);
	}
	free(str);
	str = NULL;
	return (sstr);
}

char	*norm_kekw(char *str, int fd)
{
	int		len;
	char	*buf;
	int		bz;

	len = 1;
	bz = 1;
	buf = malloc(bz + 1);
	if (!buf)
		return (NULL);
	while (len > 0 && !get_strchr(str))
	{
		len = read(fd, buf, bz);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		str = get_strjoin(str, buf);
	}
	free(buf);
	buf = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!str)
		str = get_strdup("");
	str = norm_kekw(str, fd);
	if (!str[0])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = get_line(str);
	str = get_next(str);
	return (line);
}
