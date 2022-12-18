/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/18 10:05:48 by isojo-go         ###   ########.fr       */
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
	{
		ft_close_game(game);
	}	
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		ft_printf("UP\n");
		if (game->y_pos < game->map_height - 1)
			game->y_pos++;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		ft_printf("DOWN\n");
		if (game->y_pos > 0)
			game->y_pos--;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		ft_printf("LEFT\n");
		if (game->x_pos > 0)
			game->x_pos--;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		ft_printf("RIGHT\n");
		if (game->x_pos < game->map_width - 1)
			game->x_pos++;
	}
	else
		ft_printf("Press a valid key...\n");
	ft_printf("     X: %d, Y: %d\n", game->x_pos, game->y_pos);
	game->steps++;
	ft_printf("steps: %d\n", game->steps);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[0]->content, game->x_pos * PX, (game->map_height - 1 - game->y_pos) * PX);
	return (0);
}

// Idle event
// int	ft_on_idle(int keycode, void *param)
// {
// 	t_gui	*gui;

// 	gui = param;
// 	(void)keycode;
// 	(void)gui;
// 	return (0);
// }