/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:23 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/17 23:27:37 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv, char **envp)
{
	t_game	*game;

	(void)argc;
	(void)argv;
	(void)envp;

	// TODO:
		// Check user input to console
		// Check map
		// Check map file extension
		// Check map file content (valid chars, required min chars, square size, closed, floodfill) --> Save sizes (w x h) for gui generation
		// Initialize gui
		// Define Events and Hooks
		// Start game

	// allocate memmory for game
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");
	game->x_pos = 0; // change with map
	game->y_pos = 0; // change with map
	// allocate memmory for gui
	game->gui = (t_gui *)malloc(sizeof(t_gui));
	if (game->gui == NULL)
		ft_exit_w_error("errno");

	// initialize mlx
	game->gui->mlx = mlx_init();
	if (game->gui->mlx == NULL)
		ft_exit_w_error("errno");

	// initialize the rest of params for gui
	ft_strlcpy(game->gui->title, "so_long GUI", 39);
	game->gui->width = 1200; // to be modified with map
	game->gui->height = 800; // to be modified with map
	game->gui->win = mlx_new_window(game->gui->mlx, game->gui->width, \
									game->gui->height, game->gui->title);
	if (game->gui->win == NULL)
		ft_exit_w_error("errno");
	// game->gui->img = NULL;

	// allocate memmory for images
	game->gui->img = (t_img *)malloc(sizeof(t_img));
	if (game->gui->img == NULL)
		ft_exit_w_error("errno");
	game->gui->img->img_ptr = mlx_new_image(game->gui->mlx, game->gui->width, \
											game->gui->height);
	game->gui->img->addr = mlx_get_data_addr(game->gui->img->img_ptr, \
		&game->gui->img->bpp, &game->gui->img->line_len, &game->gui->img->end);


	// Display image
	int	width;
	int	height;
	game->gui->img = mlx_xpm_file_to_image(game->gui->mlx, \
		"./assets/img48x48/xpm/player/player_1.xpm", &width, &height);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img, 10, 10);

	// Starting conditions:
	// ----------------------------------------
	ft_printf("\n\nAllocated in GUI:\n--------------\n");
	ft_printf("ptr to game: %p\nptr to gui: %p\nptr to win: %p\ntitle: %s\nwidth: %d\nheight: %d\n\n", game, game->gui, game->gui->win, game->gui->title, game->gui->width, game->gui->height);
	ft_printf("img: %p\nimg_ptr: %p\naddr: %s(%p)\nbpp: %d\nline_len: %d\nendian: %d\n\n", game->gui->img, game->gui->img->img_ptr, game->gui->img->addr, game->gui->img->addr, game->gui->img->bpp, game->gui->img->line_len, game->gui->img->end);
	// ----------------------------------------

	// DEFINE HOOKS:
	// mlx_loop_hook(gui->mlx, ft_on_idle, &gui);
	mlx_hook(game->gui->win, ON_DESTROY, 0, ft_on_destroy, &game);
	mlx_hook(game->gui->win, ON_KEYDOWN, 0, ft_on_keydown, &game);

	// Initialize GUI
	ft_printf("Initializing GUI...\n");
	mlx_loop(game->gui->mlx);


	return (EXIT_SUCCESS);
}
