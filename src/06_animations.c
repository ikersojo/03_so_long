/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:44:04 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 11:31:37 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_turn_coin(t_game *game)
{
	int	i;
	int	j;

	if (game->frame == 8)
		game->frame = 0;
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
		{
			if (*(*(game->map->grid + i) + j) == 'C')
			{
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[0], j * PX, i * PX);
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[game->frame + 9], j * PX, i * PX);
			}
		}
	}
	game->frame += 1;
}
