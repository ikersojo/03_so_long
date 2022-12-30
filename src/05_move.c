/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:35 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 11:34:12 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_found_coll(t_game *game, int x, int y)
{
	t_gui	*gui;
	char	**grid;

	grid = game->map->grid;
	gui = game->gui;
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
		(game->x_pos + x) * PX, (game->y_pos + y) * PX);
	*(*(grid + game->y_pos + y) + game->x_pos + x) = '0';
	game->collectables++;
	if (game->collectables == game->map->max_coll)
	{
		mlx_put_image_to_window(gui->mlx, gui->win,
			gui->img[8], game->x_exit * PX, game->y_exit * PX);
		ft_printf("Exit openned!\n");
	}
}

static void	ft_free_move(t_game *game, int x, int y, int player_img)
{
	t_gui	*gui;

	gui = game->gui;
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
		game->x_pos * PX, game->y_pos * PX);
	game->x_pos += x;
	game->y_pos += y;
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img[player_img],
		game->x_pos * PX, game->y_pos * PX);
	game->steps++;
}

void	ft_move(t_game *game, int x, int y, int player_img)
{
	char	**grid;

	grid = game->map->grid;
	if (*(*(grid + game->y_pos + y) + game->x_pos + x) == 'C')
	{
		ft_found_coll(game, x, y);
	}
	if ((*(*(grid + game->y_pos + y) + game->x_pos + x) == 'E'
			&& game->collectables == game->map->max_coll)
		|| (*(*(grid + game->y_pos + y) + game->x_pos + x) == 'Z'))
	{
		ft_close_game(game);
	}
	if ((*(*(grid + game->y_pos + y) + game->x_pos + x) == '0')
		|| (*(*(grid + game->y_pos + y) + game->x_pos + x) == 'P')
		|| (*(*(grid + game->y_pos + y) + game->x_pos + x) == 'E'
			&& game->collectables == game->map->max_coll))
	{
		ft_free_move(game, x, y, player_img);
	}
}
