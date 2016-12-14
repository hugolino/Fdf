/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <hdecaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 12:00:38 by hdecaux           #+#    #+#             */
/*   Updated: 2016/12/13 15:57:23 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./Libft/libft.h"

# define BUFF_SIZE 32

typedef struct	s_fd
{
	int			fd;
	char		*rest;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif
