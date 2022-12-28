/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:45:35 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/28 12:41:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_move_down(t_game *game)
{
	t_gui	*gui;
	char	**grid;

	grid = game->map->grid;
	gui = game->gui;
	if (*(*(grid + game->y_pos + 1) + game->x_pos) == 'C')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, (game->y_pos + 1) * PX);
		*(*(grid + game->y_pos + 1) + game->x_pos) = '0';
		game->collectables++;
		if (game->collectables == game->map->max_coll)
		{
			mlx_put_image_to_window(gui->mlx, gui->win,
				gui->img[8], game->x_exit * PX, game->y_exit * PX);
			ft_printf("Exit openned!\n");
		}
	}
	if (*(*(grid + game->y_pos + 1) + game->x_pos) == 'E'
		&& game->collectables == game->map->max_coll)
	{
		//animacion de final
		ft_close_game(game);
	}
	if (*(*(grid + game->y_pos + 1) + game->x_pos) != '1')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, game->y_pos * PX);
		game->y_pos++;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[3],
			game->x_pos * PX, game->y_pos * PX);
		game->steps++;
	}
}

void	ft_move_up(t_game *game)
{
	t_gui	*gui;
	char	**grid;

	grid = game->map->grid;
	gui = game->gui;
	if (*(*(grid + game->y_pos - 1) + game->x_pos) == 'C')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, (game->y_pos - 1) * PX);
		*(*(grid + game->y_pos - 1) + game->x_pos) = '0';
		game->collectables++;
		if (game->collectables == game->map->max_coll)
		{
			mlx_put_image_to_window(gui->mlx, gui->win,
				gui->img[8], game->x_exit * PX, game->y_exit * PX);
			ft_printf("Exit openned!\n");
		}
	}
	if (*(*(grid + game->y_pos - 1) + game->x_pos) == 'E'
		&& game->collectables == game->map->max_coll)
	{
		//animacion de final
		ft_close_game(game);
	}
	if (*(*(grid + game->y_pos - 1) + game->x_pos) != '1')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, game->y_pos * PX);
		game->y_pos--;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[4],
			game->x_pos * PX, game->y_pos * PX);
		game->steps++;
	}
}

void	ft_move_left(t_game *game)
{
	t_gui	*gui;
	char	**grid;

	grid = game->map->grid;
	gui = game->gui;
	if (*(*(grid + game->y_pos) + game->x_pos - 1) == 'C')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			(game->x_pos - 1) * PX, game->y_pos * PX);
		*(*(grid + game->y_pos) + game->x_pos - 1) = '0';
		game->collectables++;
		if (game->collectables == game->map->max_coll)
		{
			mlx_put_image_to_window(gui->mlx, gui->win,
				gui->img[8], game->x_exit * PX, game->y_exit * PX);
			ft_printf("Exit openned!\n");
		}
	}
	if (*(*(grid + game->y_pos) + game->x_pos - 1) == 'E'
		&& game->collectables == game->map->max_coll)
	{
		//animacion de final
		ft_close_game(game);
	}
	if (*(*(grid + game->y_pos) + game->x_pos - 1) != '1')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, game->y_pos * PX);
		game->x_pos--;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[5],
			game->x_pos * PX, game->y_pos * PX);
		game->steps++;
	}
}

void	ft_move_right(t_game *game)
{
	t_gui	*gui;
	char	**grid;

	grid = game->map->grid;
	gui = game->gui;
	if (*(*(grid + game->y_pos) + game->x_pos + 1) == 'C')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			(game->x_pos + 1) * PX, game->y_pos * PX);
		*(*(grid + game->y_pos) + game->x_pos + 1) = '0';
		game->collectables++;
		if (game->collectables == game->map->max_coll)
		{
			mlx_put_image_to_window(gui->mlx, gui->win,
				gui->img[8], game->x_exit * PX, game->y_exit * PX);
			ft_printf("Exit openned!\n");
		}
	}
	if (*(*(grid + game->y_pos) + game->x_pos + 1) == 'E'
		&& game->collectables == game->map->max_coll)
	{
		//animacion de final
		ft_close_game(game);
	}
	if (*(*(grid + game->y_pos) + game->x_pos + 1) != '1')
	{
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[0],
			game->x_pos * PX, game->y_pos * PX);
		game->x_pos++;
		mlx_put_image_to_window(gui->mlx, gui->win, gui->img[6],
			game->x_pos * PX, game->y_pos * PX);
		game->steps++;
	}
}
