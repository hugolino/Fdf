/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:45:59 by hdecaux           #+#    #+#             */
/*   Updated: 2016/12/13 17:06:12 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		fd;
	int		ret;
//	int		abs;
//	int		ord;
	int		wid;
	int		hei;
	char	*line;

	x = 0;
	y = 1;
	line = 0;
	fd = open(av[1], O_RDONLY);
	(void)ac;
	get_next_line(fd, &line);
	printf("line : %s\n", line);
	x = ft_lines(line, ' ');
	printf("nb column : %d\n", x);
	while ((ret = get_next_line(fd, &line)) > 0)
		if (ret == 1)
			y++;
	printf("nb lines : %d\n", y);
//	abs = 1100 / x;
//	ord = 1100 / y;
	wid = 230 / x;
	hei = 110 / y;
	printf("width of square : %d\n", wid);
	printf("height of square : %d\n", hei);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 240, 120, "FDF");
	y = 5;
	if (x/2 > y)
	{
		while (y <= 115)
		{
			x = 5;
			while (x <= 235)
			{
				if (x % wid == 0 || y % wid == 0)
					mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00005A25);
				x++;
			}
			y++;
		}
	}
	if (x/2 <= y)
	{
		 while (y <= 115)
	         {
			x = 5;
			while (x <= 235)
			{
				if (x % wid == 0 || y % wid == 0)
					mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00005A25);
				x++;
			}
		  y++;
		}
	}
	mlx_loop(mlx_ptr);
	return (0);
}
