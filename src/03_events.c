/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/18 22:46:19 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//destroy img, win, free all and exit
void	ft_close_game(t_game *game)
{
	int	i;
	i = 0;
	while (i < IMG_COUNT)
	{
		mlx_destroy_image(game->gui->mlx, game->gui->img[i]->img_ptr);
		free(game->gui->img[i++]);
	}
	mlx_destroy_window(game->gui->mlx, game->gui->win);
	free(game->gui->mlx);
	free(game->gui);
	free(game->map);
	free(game);
	//...no function to delete "display": potential leaks...
	ft_printf("Exiting game...\n"); //DEBUG
	exit(EXIT_SUCCESS);
}

// Event triggered by closing window (red button)
int	ft_on_destroy(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	ft_printf("Exiting game...\n"); //DEBUG
	exit(EXIT_SUCCESS);
	return (0);
}

// Event triggered by key press
int	ft_on_keydown(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	game_ptr = param;
	game = *game_ptr;
	if (keycode == KEY_ESC)
		ft_close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		ft_move_up(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_down(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move_left(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_right(game);
	system("clear");
	ft_printf("steps: %d\n", game->steps); // BORRAR
	return (0);
}

// Idle event
int	ft_on_idle(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	game_ptr = param;
	game = *game_ptr;
	(void)keycode;
	(void)game; // DEBUG
	return (0);
}