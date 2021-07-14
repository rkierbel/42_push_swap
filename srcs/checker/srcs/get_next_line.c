/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:23:46 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:23:56 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*object;
	size_t			i;

	i = 0;
	object = malloc(count * size);
	if (object == NULL)
		return (NULL);
	while (i < count * size)
	{
		object[i] = 0;
		i++;
	}
	return ((void *)object);
}

int	ft_find_newline_char(char *buf, char nl)
{
	int	i;

	i = 0;
	if (buf[i])
	{
		while (buf[i] && buf[i] != nl)
			i++;
		if (buf[i] == nl)
			return (i);
	}
	return (-1);
}

ssize_t	perform_reads(char **save, ssize_t ret, char *buf, int fd)
{
	if (save[fd] != NULL)
	{
		ft_strcpy(buf, save[fd]);
		free(save[fd]);
		save[fd] = NULL;
	}
	else
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
	}
	return (ret);
}

int	ft_create_line(char *buf, char **line, char **save, int fd)
{
	int		i;
	char	*tmp;
	char	*buf_with_nl;

	i = ft_find_newline_char(buf, '\n');
	if (i != -1)
	{
		buf_with_nl = ft_substr(buf, 0, i);
		tmp = *line;
		*line = ft_strjoin(tmp, buf_with_nl);
		free(tmp);
		free(buf_with_nl);
		if (buf + i + 1 != NULL)
			save[fd] = ft_strdup(buf + i + 1);
		return (1);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*save[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	*line = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = perform_reads(save, ret, buf, fd);
		if (ret < 0)
			return (-1);
		if (!*line)
			*line = ft_calloc(1, sizeof(char));
		if (ft_create_line(buf, &*line, save, fd) == 1)
			return (1);
	}
	return (0);
}
