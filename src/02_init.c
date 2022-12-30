/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:49:46 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 12:04:55 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_load(t_game *game, char *path, int i)
{
	int		w;
	int		h;

	game->gui->img[i] = mlx_xpm_file_to_image(game->gui->mlx, path, &w, &h);
	if (game->gui->img[i] == NULL)
		ft_exit_w_error(".xpm file not found");
}

static void	ft_load_imgs(t_game *game)
{
	char	files[IMG_COUNT][80];
	int		i;

	ft_strlcpy(files[0], FLOOR, 79);
	ft_strlcpy(files[1], WALL, 79);
	ft_strlcpy(files[2], COLL, 79);
	ft_strlcpy(files[3], PLAYER_D, 79);
	ft_strlcpy(files[4], PLAYER_U, 79);
	ft_strlcpy(files[5], PLAYER_L, 79);
	ft_strlcpy(files[6], PLAYER_R, 79);
	ft_strlcpy(files[7], EXIT_C, 79);
	ft_strlcpy(files[8], EXIT_O, 79);
	ft_strlcpy(files[9], COLL_A_1, 79);
	ft_strlcpy(files[10], COLL_A_2, 79);
	ft_strlcpy(files[11], COLL_A_3, 79);
	ft_strlcpy(files[12], COLL_A_4, 79);
	ft_strlcpy(files[13], COLL_A_5, 79);
	ft_strlcpy(files[14], COLL_A_6, 79);
	ft_strlcpy(files[15], COLL_A_7, 79);
	ft_strlcpy(files[16], COLL_A_8, 79);
	i = -1;
	while (++i < IMG_COUNT)
		ft_load(game, files[i], i);
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

static void	ft_get_starting_pos(t_game *game)
{
	int		i;
	int		j;
	char	**grid;

	grid = game->map->grid;
	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
		{
			if (*(*(grid + i) + j) == 'P')
			{
				game->y_pos = i;
				game->x_pos = j;
			}
			else if (*(*(grid + i) + j) == 'E')
			{
				game->y_exit = i;
				game->x_exit = j;
			}
		}
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
	game->frame = 0;
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
