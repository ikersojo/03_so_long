/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:25:55 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/28 12:39:16 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_print_map(t_game *game)
{
	int		i;
	int		j;
	char	**grid;

	grid = game->map->grid;
	// Add floor
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
			mlx_put_image_to_window(game->gui->mlx, game->gui->win,
				game->gui->img[0], j * PX, i * PX);
	}
	// Add walls, collectables and exit
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
		{
			if (*(*(grid + i) + j)  == '1')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[1], j * PX, i * PX);
			else if (*(*(grid + i) + j)  == 'C')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[2], j * PX, i * PX);
			else if (*(*(grid + i) + j)  == 'E')
			{
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[7], j * PX, i * PX);
				game->x_exit = j;
				game->y_exit = i;
			}
			//añadir letra para enemigos en caso de bonus
		}
	}
	// Add player
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[3],
		game->x_pos * PX, game->y_pos * PX);
}
