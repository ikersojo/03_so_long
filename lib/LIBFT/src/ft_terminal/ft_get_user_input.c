/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:30 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/13 20:28:01 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Promts the user with str, and returns the user input from STDIN as string.
The user escape character is a new line (ENTER KEY PRESS).
The string returned is allocated with malloc and must be freed.
---------------------------------------------------------------------------- */
char	*ft_get_user_input(char *str)
{
	char	c;
	int		bytes;
	char	*line;
	int		i;

	ft_putstr_fd(str, 1);
	line = (char *)malloc(400);
	if (!line)
		return (NULL);
	bytes = read(0, &c, 1);
	i = 0;
	while (bytes > 0 && c != '\0' && i < 395)
	{
		if (c == '\n')
			break ;
		*(line + i++) = c;
		bytes = read(0, &c, 1);
	}
	*(line + i) = '\0';
	return (line);
}
