/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:23 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/19 23:28:48 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->h)
	{
		j = 0;
		while (j < game->map->w)
		{
			mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[0]->content, j * PX, i * PX);
			
			//DEBUG, to be replaced by map content...
			if (i == 0 || i == game->map->h - 1)
				mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[1]->content, j * PX, i * PX);
			
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[3]->content, game->x_pos * PX, (game->map->h - 1 - game->y_pos) * PX);

}

void	ft_load_imgs(t_game *game)
{
	int		width;
	int		height;
	int		i;
	char	files[IMG_COUNT][80];

	ft_strlcpy(files[0], FLOOR, 79);
	ft_strlcpy(files[1], WALL, 79);
	ft_strlcpy(files[2], COLL, 79);
	ft_strlcpy(files[3], PLAYER_D, 79);
	ft_strlcpy(files[4], PLAYER_U, 79);
	ft_strlcpy(files[5], PLAYER_L, 79);
	ft_strlcpy(files[6], PLAYER_R, 79);
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
		game->gui->img[i]->content = mlx_xpm_file_to_image(game->gui->mlx, \
			files[i], &width, &height);
		i++;
	}
}

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
	gui->width = game->map->w * PX;
	gui->height = game->map->h * PX;
	gui->win = mlx_new_window(gui->mlx, gui->width, gui->height, gui->title);
	if (gui->win == NULL)
		ft_exit_w_error("errno3");
	return (gui);
}

t_game	*ft_initialize_game(char *map_file) //tendremos que pasarle el mapa
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		ft_exit_w_error("errno");
	game->steps = 0;
	game->collectables = 0;
	game->x_pos = 3; // change with map
	game->y_pos = 7; // change with map
	game->map->w = 20; // to be modified with map
	game->map->h = 20; // to be modified with map
	game->gui = ft_initialize_gui(game);
	ft_load_imgs(game);
	ft_print_map(game);
	return (game);
}

static int	ft_ext_ok(char *str)
{
	if (!ft_strnstr(str + ft_strlen(str) - 4, ".ber", 4))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_ext_ok(*(argv + 1)))
	{
		ft_check_map(*(argv + 1));
		game = ft_initialize_game(*(argv + 1)); //pasarle el mapa: game = ft_initialize_game(*(argv + 1));
		
		// DEFINE HOOKS:
		// mlx_loop_hook(gui->mlx, ft_on_idle, &gui);
		mlx_hook(game->gui->win, ON_DESTROY, 0, ft_on_destroy, &game);
		mlx_hook(game->gui->win, ON_KEYDOWN, 0, ft_on_keydown, &game);

		// Initialize GUI
		ft_printf("Initializing GUI...\n");
		mlx_loop(game->gui->mlx);
	}
	else
		ft_exit_w_error("syntax: ./bin/so_long xxxxxx.ber\n");
	return (EXIT_SUCCESS);
}
