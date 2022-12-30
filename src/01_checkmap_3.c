/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checkmap_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:10:00 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 11:31:02 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_paint_grid(char **grid, t_size size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size.h)
	{
		ft_putstr_fd("      ", 1);
		j = -1;
		while (++j < size.w)
		{
			if (*(*(grid + i) + j) == '1')
				ft_putstr_fd("\033[0;31m", 1);
			else if (*(*(grid + i) + j) == '0')
				ft_putstr_fd("\033[0;39m", 1);
			else if (*(*(grid + i) + j) == 'x')
				ft_putstr_fd("\033[0;92m", 1);
			else
				ft_putstr_fd("\033[0;93m", 1);
			ft_putchar_fd(*(*(grid + i) + j), 1);
			ft_putstr_fd(" \033[0;39m", 1);
		}
		ft_putstr_fd("\n\033[0;39m", 1);
	}
	ft_putchar_fd('\n', 1);
}

static void	ft_fill(char **grid, t_size sz, int x, int y)
{
	if (x < 0 || y < 0 || x >= sz.w || y >= sz.h || *(*(grid + y) + x) == '1')
		return ;
	if (*(*(grid + y) + x) == 'x')
		return ;
	if (*(*(grid + y) + x) == '0' || *(*(grid + y) + x) == 'C'
		|| *(*(grid + y) + x) == 'P')
	{
		*(*(grid + y) + x) = 'x';
		ft_fill(grid, sz, x + 1, y);
		ft_fill(grid, sz, x - 1, y);
		ft_fill(grid, sz, x, y + 1);
		ft_fill(grid, sz, x, y - 1);
	}
}

static int	ft_check_grid(char **grid, t_size sz)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = -1;
	while (++i < sz.h)
	{
		j = -1;
		while (++j < sz.w)
		{
			if (*(*(grid + i) + j) == 'C')
				return (0);
			else if ((*(*(grid + i) + j) == 'E')
				&& (*(*(grid + i + 1) + j) == 'x'
					|| *(*(grid + i - 1) + j) == 'x'
					|| *(*(grid + i) + j + 1) == 'x'
					|| *(*(grid + i) + j - 1) == 'x'))
				res = 1;
		}
	}
	return (res);
}

static int	ft_floodfill(char **grid, int width, int height)
{
	t_size	size;
	int		i;
	int		j;
	int		coord[2];

	size.w = width;
	size.h = height;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (*(*(grid + i) + j) == 'P')
			{
				coord[1] = i;
				coord[0] = j;
			}
		}
	}
	ft_fill(grid, size, coord[0], coord[1]);
	ft_paint_grid(grid, size);
	return (ft_check_grid(grid, size));
}

int	ft_feasibility(char *str, int width, int height)
{
	char	**grid;
	int		i;
	int		res;

	grid = ft_gen_map_grid(str, width, height);
	res = ft_floodfill(grid, width, height);
	i = 0;
	while (i < height)
		free (*((grid) + i++));
	free(grid);
	return (res);
}
