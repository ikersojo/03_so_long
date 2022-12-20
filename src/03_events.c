/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:56 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/20 13:54:54 by isojo-go         ###   ########.fr       */
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
		ft_printf("img[%d]: (%p) - content (%p) - ptr(%p) - adrr(%p) being freed\n", i, game->gui->img[i], game->gui->img[i]->content, game->gui->img[i]->img_ptr, game->gui->img[i]->addr); // DEBUG
		mlx_destroy_image(game->gui->mlx, game->gui->img[i]->img_ptr);
		mlx_destroy_image(game->gui->mlx, game->gui->img[i]->content);
		// mlx_destroy_image(game->gui->mlx, game->gui->img[i]->addr);
		free(game->gui->img[i++]);
	}

	ft_printf("\nwin: (%p) being destroyed\n", game->gui->win); // DEBUG
	mlx_destroy_window(game->gui->mlx, game->gui->win);

	ft_printf("mlx: (%p) being freed\n", game->gui->mlx); // DEBUG
	free(game->gui->mlx);

	ft_printf("gui: (%p) being freed\n", game->gui); // DEBUG
	free(game->gui);

	ft_printf("map: (%p) being freed\n", game->map); // DEBUG
	free(game->map);

	ft_printf("game: (%p) being freed\n", game); // DEBUG
	free(game);

	//...no function to delete "display": potential leaks...
	
	ft_printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
}

// Event triggered by closing window (red button)
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
	ft_printf("steps: %d (x: %d, y: %d)\n", game->steps, game->x_pos, game->y_pos); // sustituir estas 2 por una guay
	return (0);
}

// Idle event
// int	ft_on_idle(int keycode, void *param)
// {
// 	t_game	**game_ptr;
// 	t_game	*game;

// 	game_ptr = param;
// 	game = *game_ptr;
// 	(void)keycode;
// 	(void)game; // DEBUG
// 	return (0);
// }