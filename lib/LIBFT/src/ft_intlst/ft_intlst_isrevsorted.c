/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_isrevsorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:21:46 by isojo-go          #+#    #+#             */
/*   Updated: 2022/11/05 09:23:39 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* DESCRIPTION:
Takes as a parameter the adress of a pointer to the first element of a list of
integers and checks if the list is reverse sorted.
---------------------------------------------------------------------------- */

int	ft_intlst_isrevsorted(t_intlst *lst)
{
	while (lst->next)
	{
		if (lst->value < lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
