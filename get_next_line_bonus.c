/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:25:56 by naessgui          #+#    #+#             */
/*   Updated: 2025/01/02 17:41:52 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line(char *hold)
{
	char	*buffer;
	int		i;
	int		k;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		i++;
	buffer = malloc(i + 1);
	if (!buffer)
		return (NULL);
	k = 0;
	while (k < i)
	{
		buffer[k] = hold[k];
		k++;
	}
	buffer[k] = '\0';
	return (buffer);
}

char	*rest(char *hold, int len)
{
	char	*end;
	int		len_hold;
	int		i;

	if (!hold)
		return (NULL);
	len_hold = ft_strlen(hold);
	if (len_hold - len <= 0)
		return (free(hold), hold = NULL, NULL);
	end = malloc(len_hold - len + 1);
	if (!end)
		return (NULL);
	i = 0;
	while (len < len_hold)
	{
		end[i] = hold[len];
		len++;
		i++;
	}
	end[i] = '\0';
	return (free(hold), hold = NULL, end);
}

char	*get_next_line(int fd)
{
	static char	*hold[10240];
	char		*buff;
	char		*ln;
	int			rd;
	int			len;

	rd = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buff)
		return (free(buff), buff = NULL, NULL);
	while (rd)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (free(hold[fd]), hold[fd] = NULL, free(buff),
				buff = NULL, NULL);
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		hold[fd] = ft_strjoin(hold[fd], buff);
		if (ft_strchr(hold[fd], '\n'))
			break ;
	}
	return (free(buff), buff = NULL, ln = line(hold[fd]), len = ft_strlen(ln),
		hold[fd] = rest(hold[fd], len), ln);
}
