/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:49:46 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/28 11:55:40 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_load_imgs(t_game *game)
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
	ft_strlcpy(files[7], EXIT_C, 79);
	ft_strlcpy(files[8], EXIT_O, 79);
	//añadir enemigos
	//añadir necesarias para animaciones
	i = -1;
	while (++i < IMG_COUNT)
	{
		// comprobar que existe el fichero de imagen
		game->gui->img[i] = mlx_xpm_file_to_image(game->gui->mlx, files[i],
			&width, &height);
		if (game->gui->img[i] == NULL)
			ft_exit_w_error("errno");
	}
}

static t_gui	*ft_initialize_gui(t_game *game)
{
	t_gui	*gui;

	gui = (t_gui *)malloc(sizeof(t_gui));
	if (gui == NULL)
		ft_exit_w_error("errno");
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		ft_exit_w_error("errno");
	gui->width = game->map->w * PX;
	gui->height = game->map->h * PX;
	gui->win = mlx_new_window(gui->mlx, gui->width, gui->height, "so_long");
	if (gui->win == NULL)
		ft_exit_w_error("errno");
	return (gui);
}

static char	**ft_gen_map_grid(char *map_file, int w, int h)
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

static void	ft_get_starting_pos(t_game *game)
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
