/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checkmap_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:28:27 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 12:00:17 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**ft_gen_map_grid(char *map_file, int w, int h)
{
	char	**grid;
	int		mapfd;
	char	*line;
	int		i;
	int		j;

	mapfd = open(map_file, O_RDONLY);
	if (mapfd == -1)
		ft_exit_w_error("errno");
	grid = (char **)malloc(sizeof(char *) * h);
	i = 0;
	while (i < h)
	{
		line = ft_gnl(mapfd);
		*(grid + i) = (char *)malloc(sizeof(char) * w);
		j = -1;
		while (++j < w)
			*(*(grid + i) + j) = *(line + j);
		i++;
		free (line);
	}
	return (grid);
}

int	ft_check_map(char *str, int *width, int *height, int *coll)
{
	*width = 0;
	*height = 0;
	*coll = 0;
	ft_printf("Checking map...\n");
	if (ft_check_rect(str, width, height) == 0)
		ft_exit_w_error("\nThe map does not have rectangular shape.\n");
	ft_printf(" - map is rectangular (w:%d x h:%d):", *width, *height);
	ft_printf(" \033[0;92m[OK]\033[0;39m\n\n");
	if (ft_check_chars(str, width, height, coll) == 0)
		ft_exit_w_error("\nThe map contains more/less chars than allowed.\n");
	ft_printf(" - map includes required chars (%d collectable(s)):", *coll);
	ft_printf(" \033[0;92m[OK]\033[0;39m\n\n");
	if (ft_feasibility(str, *width, *height) == 0)
		ft_exit_w_error("\nThe map cannot be completed.\n");
	ft_printf(" - map can be completed:");
	ft_printf(" \033[0;92m[OK]\033[0;39m\n\n");
	return (1);
}
