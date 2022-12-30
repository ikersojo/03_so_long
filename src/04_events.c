/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 18:30:09 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_close_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < IMG_COUNT)
		mlx_destroy_image(game->gui->mlx, game->gui->img[i++]);
	mlx_destroy_window(game->gui->mlx, game->gui->win);
	free(game->gui->mlx);
	free(game->gui);
	i = 0;
	while (i < game->map->h)
		free (*((game->map->grid) + i++));
	free(game->map->grid);
	free(game->map);
	free(game);
	ft_printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
}

int	ft_on_destroy(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	(void)keycode;
	game_ptr = param;
	game = *game_ptr;
	(void)game;
	ft_printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_on_keydown(int keycode, void *param)
{
	t_game		**game_ptr;
	t_game		*game;

	game_ptr = param;
	game = *game_ptr;
	if (keycode == KEY_ESC)
		ft_close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		ft_move(game, 0, -1, 4);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move(game, 0, 1, 3);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move(game, -1, 0, 5);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move(game, 1, 0, 6);
	system("clear");
	ft_printf("steps: %d\n", game->steps);
	ft_printf("collectables: %d / %d\n", game->collectables,
		game->map->max_coll);
	ft_print_counters(game);
	ft_turn_coin(game);
	return (0);
}

int	ft_on_idle(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	game_ptr = param;
	game = *game_ptr;
	(void)keycode;
	(void)game;
	return (0);
}
