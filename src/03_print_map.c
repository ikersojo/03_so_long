/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:25:55 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 13:26:10 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_clean_background(t_game *game)
{
	int		j;

	j = -1;
	while (++j < 6)
	{
		mlx_put_image_to_window(game->gui->mlx, game->gui->win,
			game->gui->img[0], j * PX, 0);
		mlx_put_image_to_window(game->gui->mlx, game->gui->win,
			game->gui->img[1], j * PX, 0);
	}
}

void	ft_print_counters(t_game *game)
{
	char	*coll_str1;
	char	*coll_str2;
	char	*coll_str3;
	char	*max_coll;

	ft_clean_background(game);
	mlx_string_put (game->gui->mlx, game->gui->win, 6, 12, 0, "steps:");
	coll_str1 = ft_itoa(game->steps);
	mlx_string_put (game->gui->mlx, game->gui->win, PX, 12, 0, coll_str1);
	free(coll_str1);
	mlx_string_put (game->gui->mlx, game->gui->win, 6, 24, 0, "coins: ");
	max_coll = ft_itoa(game->map->max_coll);
	coll_str1 = ft_itoa(game->collectables);
	coll_str2 = ft_strjoin(coll_str1, " / ");
	coll_str3 = ft_strjoin(coll_str2, max_coll);
	mlx_string_put (game->gui->mlx, game->gui->win, PX, 24, 0, coll_str3);
	free(max_coll);
	free(coll_str1);
	free(coll_str2);
	free(coll_str3);
}

static void	ft_add_floor(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->map->h)
	{
		j = -1;
		while (++j < game->map->w)
			mlx_put_image_to_window(game->gui->mlx, game->gui->win,
				game->gui->img[0], j * PX, i * PX);
	}
}

void	ft_print_map(t_game *game)
{
	int		i[2];

	ft_add_floor(game);
	i[0] = -1;
	while (++i[0] < game->map->h)
	{
		i[1] = -1;
		while (++i[1] < game->map->w)
		{
			if (*(*(game->map->grid + i[0]) + i[1]) == '1')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[1], i[1] * PX, i[0] * PX);
			else if (*(*(game->map->grid + i[0]) + i[1]) == 'C')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[2], i[1] * PX, i[0] * PX);
			else if (*(*(game->map->grid + i[0]) + i[1]) == 'E')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[7], i[1] * PX, i[0] * PX);
			else if (*(*(game->map->grid + i[0]) + i[1]) == 'Z')
				mlx_put_image_to_window(game->gui->mlx, game->gui->win,
					game->gui->img[17], i[1] * PX, i[0] * PX);
		}
	}
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img[3],
		game->x_pos * PX, game->y_pos * PX);
}
