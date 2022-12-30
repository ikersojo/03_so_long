/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checkmap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:48:45 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 13:22:49 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_get_line_length(int mapfd, int *width, int *height)
{
	char	*line;
	int		line_length;

	line = ft_gnl(mapfd);
	line_length = ft_strlen(line);
	if (line_length == 0)
	{
		free (line);
		return (0);
	}
	if (*(line + line_length - 1) == '\n')
		line_length -= 1;
	if (*height == 0)
		*width = line_length;
	if (*width != line_length)
	{
		free(line);
		return (-1);
	}
	(*height)++;
	free (line);
	return (line_length);
}

int	ft_check_rect(char *str, int *width, int *height)
{
	int		mapfd;
	int		line_length;

	mapfd = open(str, O_RDONLY);
	if (mapfd == -1)
		ft_exit_w_error("errno");
	while (1)
	{
		line_length = ft_get_line_length(mapfd, width, height);
		if (line_length == 0 || line_length == -1)
			break ;
	}
	close (mapfd);
	if (*height < 3 || *width < 5 || line_length == -1)
		return (0);
	return (1);
}

static void	initialize_vars(int *i, int *player, int *exit)
{
	*player = 0;
	*exit = 0;
	*i = -1;
}

static void	update_vars(char *line, int *player, int *exit, int *coll)
{
		*player += ft_count_chars(line, 'P');
		*exit += ft_count_chars(line, 'E');
		*coll += ft_count_chars(line, 'C');
}

// v: i, player, exit, mapfd
int	ft_check_chars(char *str, int *w, int *h, int *coll)
{
	int		v[4];
	char	*l;
	char	*valid;

	valid = ft_allowed_c();
	v[3] = open(str, O_RDONLY);
	initialize_vars(&v[2], &v[0], &v[1]);
	while (++v[2] < *h && v[2] > -2)
	{
		l = ft_gnl(v[3]);
		if ((v[2] == 0 || v[2] == *h - 1) && (ft_count_chars(l, '1') != *w))
			v[2] = -10;
		else if (v[2] != 0 && v[2] != *h - 1)
		{
			update_vars(l, &v[0], &v[1], coll);
			if (*l != '1' || *(l + *w - 1) != '1' || !ft_only_c(l, valid))
				v[2] = -10;
		}
		free (l);
	}
	free (valid);
	close (v[3]);
	if (v[0] != 1 || v[1] != 1 || *coll < 1 || v[2] < -2)
		return (0);
	return (1);
}
