/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:35 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/20 14:06:58 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_down(t_game *game)
{
	t_gui	*gui;

	gui = game->gui;
	if (game->y_pos - 1 > 0)
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->y_pos--;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[3], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->steps++;
	}
}

void	ft_move_up(t_game *game)
{
	t_gui	*gui;

	gui = game->gui;
	if (game->y_pos < game->map->h)
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->y_pos++;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[4], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->steps++;
	}
}

void	ft_move_left(t_game *game)
{
	t_gui	*gui;

	gui = game->gui;
	if (game->x_pos > 0)
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->x_pos--;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[5], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->steps++;
	}
}

void	ft_move_right(t_game *game)
{
	t_gui	*gui;

	gui = game->gui;
	if (game->x_pos < game->map->w - 1)
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->x_pos++;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[6], \
			game->x_pos * PX, (game->map->h - game->y_pos) * PX);
		game->steps++;
	}
}
