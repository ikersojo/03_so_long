/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_allowed_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:00:39 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 13:06:43 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_allowed_c(void)
{
	char	*str;

	str = ft_strdup("01EPC\n");
	return (str);
}
