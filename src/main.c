/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:23 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/18 11:19:08 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_gui	*ft_initialize_gui(t_game *game)
{
	t_gui	*gui;

	gui = (t_gui *)malloc(sizeof(t_gui));
	if (gui == NULL)
		ft_exit_w_error("errno1");

	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		ft_exit_w_error("errno2");
	ft_strlcpy(gui->title, "so_long GUI", 39);
	gui->width = game->map_width * PX;
	gui->height = game->map_height * PX;
	gui->win = mlx_new_window(gui->mlx, gui->width, gui->height, gui->title);
	if (gui->win == NULL)
		ft_exit_w_error("errno3");
	return (gui);
}

t_game	*ft_initialize_game(void) //tendremos que pasarle el mapa
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");
	game->steps = 0;
	game->collectables = 0;
	game->x_pos = 0; // change with map
	game->y_pos = 0; // change with map
	game->map_width = 20; // to be modified with map
	game->map_height = 20; // to be modified with map
	game->gui = ft_initialize_gui(game);
	return (game);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	*game;


	// TODO:
		// Check user input to console
	(void)argc;
	(void)argv;
	(void)envp;
		// Check map
		// Check map file extension
		// Check map file content (valid chars, required min chars, square size, closed, floodfill) --> Save sizes (w x h) for gui generation
		// Initialize gui
		// Define Events and Hooks
		// Start game

	game = ft_initialize_game();
	// allocate memmory for images
	int	i;
	i = 0;
	while (i < IMG_COUNT)
	{
		game->gui->img[i] = (t_img *)malloc(sizeof(t_img));
		if (game->gui->img[i] == NULL)
			ft_exit_w_error("errno");
		game->gui->img[i]->img_ptr = mlx_new_image(game->gui->mlx, game->gui->width, \
												game->gui->height);
		game->gui->img[i]->addr = mlx_get_data_addr(game->gui->img[i]->img_ptr, \
			&game->gui->img[i]->bpp, &game->gui->img[i]->line_len, &game->gui->img[i]->endian);
		i++;
	}


	// Display image
	int	width;
	int	height;

	game->gui->img[0]->content = mlx_xpm_file_to_image(game->gui->mlx, \
		PLAYER, &width, &height);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[0]->content, game->x_pos * PX, (game->map_height - 1 - game->y_pos) * PX);

	// Starting conditions:
	// ----------------------------------------
	ft_printf("\n\nAllocated in GUI:\n--------------\n");
	ft_printf("ptr to game: %p\nptr to gui: %p\nptr to win: %p\ntitle: %s\nwidth: %d\nheight: %d\n\n", game, game->gui, game->gui->win, game->gui->title, game->gui->width, game->gui->height);
	i = 0;
	while (i < IMG_COUNT)
	{
		ft_printf("\n--------------\nimg: %p\nimg_content: %p\nimg_ptr: %p\naddr: %s(%p)\nbpp: %d\nline_len: %d\nendian: %d\n\n", game->gui->img, game->gui->img[i]->content, game->gui->img[i]->img_ptr, game->gui->img[i]->addr, game->gui->img[i]->addr, game->gui->img[i]->bpp, game->gui->img[i]->line_len, game->gui->img[i]->endian);
		i++;
	}

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
