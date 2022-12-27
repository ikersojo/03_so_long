/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:23 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/24 10:53:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_print_map(t_game *game)
{
	int		i;
	int		j;
	char	**grid;

	grid = game->map->grid;
	// Add floor
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
			mlx_put_image_to_window(game->gui->mlx, game->gui->win, \
				game->gui->img[0], j * PX, i * PX);
	}
	// Add walls
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
		{
			if (*(*(grid + i) + j)  == '1')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win, \
					game->gui->img[1], j * PX, i * PX);
			else if (*(*(grid + i) + j)  == 'C')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win, \
					game->gui->img[2], j * PX, i * PX);
			else if (*(*(grid + i) + j)  == 'E')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win, \
					game->gui->img[3], j * PX, i * PX); //modificar imagen
		}
	}
	// Add player
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[3],\
		game->x_pos * PX, (game->map->h - game->y_pos) * PX);
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
		game->gui->img[i] = mlx_xpm_file_to_image(game->gui->mlx, files[i], \
			&width, &height);
		i++;
	}
}

t_gui	*ft_initialize_gui(t_game *game)
{
	t_gui	*gui;

	gui = (t_gui *)malloc(sizeof(t_gui));
	if (gui == NULL)
		ft_exit_w_error("errno");
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		ft_exit_w_error("errno");
	// ft_strlcpy(gui->title, "so_long GUI", 39);
	gui->width = game->map->w * PX;
	gui->height = game->map->h * PX;
	gui->win = mlx_new_window(gui->mlx, gui->width, gui->height, "so_long GUI");
	if (gui->win == NULL)
		ft_exit_w_error("errno");
	return (gui);
}

char	**ft_gen_map_grid(char *map_file, int w, int h)
{
	char	**grid;
	int		mapfd;
	char	*line;
	int		i;
	int		j;

	mapfd = open(map_file, O_RDONLY);
	if (mapfd == -1)
		ft_exit_w_error("errno");
	grid = (char **)malloc(sizeof(char *) * h);
	i = 0;
	while (i < h)
	{
		line = ft_gnl(mapfd);
		*(grid + i) = (char *)malloc(sizeof(char) * w);
		j = -1;
		while (++j < w)
			*(*(grid + i) + j) = *(line + j);
		i++;
		free (line);
	}
	return (grid);
}

void	ft_get_starting_pos(t_game *game)
{
	int		i;
	int		j;
	char	**grid;

	grid = game->map->grid;
	i = 0;
	while (i < game->map->h)
	{
		j = 0;
		while (j < game->map->w)
		{
			if (*(*(grid + i) + j)  == 'P')
			{
				game->y_pos = i;
				game->x_pos = j;
				ft_printf("starting pos: x = %d, y = %d\n", game->x_pos, game->y_pos); // DEBUG
				return ;
			}
			j++;
		}
		i++;
	}
}

t_game	*ft_initialize_game(char *map_file)
{
	t_game	*game;
	int		width;
	int		height;
	int		coll;

	ft_check_map(map_file, &width, &height, &coll);
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");
	game->steps = 0;
	game->collectables = 0;
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		ft_exit_w_error("errno");
	game->map->w = width;
	game->map->h = height;
	game->map->max_coll = coll;
	game->map->grid = ft_gen_map_grid(map_file, width, height);
	ft_get_starting_pos(game);
	game->gui = ft_initialize_gui(game);
	ft_load_imgs(game);
	ft_print_map(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_ext_ok(*(argv + 1), ".ber"))
	{
		game = ft_initialize_game(*(argv + 1));
		
		// DEFINE HOOKS:
		mlx_loop_hook(game->gui->mlx, ft_on_idle, &game);
		mlx_hook(game->gui->win, ON_DESTROY, 1L << 17, ft_on_destroy, &game);
		mlx_hook(game->gui->win, ON_KEYDOWN, 0, ft_on_keydown, &game);

		// Initialize GUI
		ft_printf("Initializing GUI...\n");
		mlx_loop(game->gui->mlx);
	}
	else
		ft_exit_w_error("syntax: ./bin/so_long xxxxxx.ber\n");
	return (EXIT_SUCCESS);
}
