/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:45:29 by hdecaux           #+#    #+#             */
/*   Updated: 2016/12/13 13:00:06 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd	*actual_fd(int const fd, t_list **fds)
{
	t_list	*tmp;
	t_fd	content;

	tmp = *fds;
	while (tmp != NULL)
	{
		if (((t_fd *)tmp->content)->fd == fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	content.fd = fd;
	content.rest = NULL;
	ft_lstadd(fds, ft_lstnew((void *)&content, sizeof(content)));
	return ((*fds)->content);
}

static int	ft_rest(t_fd *actual, char **line)
{
	char *tmp;

	tmp = ft_strchr(actual->rest, '\n');
	if (tmp)
	{
		*line = ft_strsub(actual->rest, 0, tmp - actual->rest);
		ft_memmove(actual->rest, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int	ft_read(int fd, t_fd *actual, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (actual->rest)
			actual->rest = ft_strjoin_free(actual->rest, buf, 1);
		else
			actual->rest = ft_strdup(buf);
		if (ft_rest(actual, line))
			return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*fds = NULL;
	t_fd			*actual;
	int				read;

	if (!line || fd < 0)
		return (-1);
	actual = actual_fd(fd, &fds);
	if (actual->rest && ft_rest(actual, line))
		return (1);
	if ((read = ft_read(fd, actual, line)) != 0)
		return (read);
	if (actual->rest == NULL || actual->rest[0] == '\0')
		return (0);
	*line = actual->rest;
	actual->rest = NULL;
	return (1);
}
