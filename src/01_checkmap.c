/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:48:45 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/28 10:21:41 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_count_chars(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static int	ft_check_rect(char *str, int *width, int *height)
{
	int		mapfd;
	char	*line;
	int		line_length;

	mapfd = open(str, O_RDONLY);
	if (mapfd == -1)
		ft_exit_w_error("errno");
	while (1)
	{
		line = ft_gnl(mapfd);
		line_length = ft_strlen(line);
		if (line_length == 0)
		{
			free (line);
			break ;
		}
		if (*(line + line_length - 1) == '\n')
			line_length -= 1;
		if (*height == 0)
			*width = line_length;
		if (*width != line_length)
		{
			free(line);
			return (0);
		}
		(*height)++;
		free (line);
	}
	close (mapfd);
	if (*height < 3 || *width < 5)
		return (0);
	return (1);
}

int	ft_chars_valid(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!ft_ischarset(*(str + i++), "01EPC\n"))
			return (0);
	}
	return (1);
}

static int	ft_check_chars(char *str, int *width, int *height, int *coll)
{
	int		mapfd;
	char	*line;
	int		i;
	int		player;
	int		exit;

	mapfd = open(str, O_RDONLY);
	if (mapfd == -1)
		ft_exit_w_error("errno");
	player = 0;
	exit = 0;
	i = -1;
	while (++i < *height)
	{
		line = ft_gnl(mapfd);
		ft_printf("    %s", line); // DEBUG
		if (i == 0 || i == *height - 1)
		{
			if (ft_count_chars(line, '1') != *width)
			{
				free (line);
				close (mapfd);
				return (0);
			}
		}
		else
		{
			player += ft_count_chars(line, 'P');
			exit += ft_count_chars(line, 'E');
			*coll += ft_count_chars(line, 'C');
			if (*line != '1' || *(line + *width - 1) != '1' || !ft_chars_valid(line))
			{
				free(line);
				close (mapfd);
				return (0);
			}
			free (line);
		}
	}
	close (mapfd);
	if (player != 1 || exit != 1 || *coll < 1)
		return (0);
	return (1);
}

// static int	ft_check_feasibity(char *str, int *width, int *height)
// {
	
// 	return (1);
// }

int	ft_check_map(char *str, int *width, int *height, int *coll)
{
	*width = 0;
	*height = 0;
	*coll = 0;
	if (ft_check_rect(str, width, height) == 0)
		ft_exit_w_error("\nThe maps does not have rectangular shape.\n");
	ft_printf("\nmap is rectangular (w:%d x h:%d):\n\n", *width, *height); // DEBUG
	if (ft_check_chars(str, width, height, coll) == 0)
		ft_exit_w_error("\nThe maps contains more/less chars than allowed.\n");
	ft_printf("\n\nmap chars ok (%d collectables)\n\n", *coll); // DEBUG
	// Tienes que comprobar si hay un camino válido en el mapa.
	// if (ft_feasibility(str, &width, &height) == 0)
	// 	ft_exit_w_error("\nThe maps cannot be completed.\n");
	return (1);
}