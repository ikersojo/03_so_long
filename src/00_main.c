/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:44:23 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/28 09:30:39 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		ft_printf("Initializing GUI...\n"); // modificar por algo chulo
		mlx_loop(game->gui->mlx);
	}
	else
		ft_exit_w_error("syntax: ./bin/so_long xxxxxx.ber\n");
	return (EXIT_SUCCESS);
}
