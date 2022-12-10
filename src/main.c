/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:32:20 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/10 20:33:55 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/inc/libft.h"
#include "../lib/LIBMLX/inc/mlx.h"

int	main(int argc, char **argv, char **envp)
{
	void	*mlx;
	void	*window;
	char	*title;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	if (mlx == NULL)
		ft_exit_w_error("errno");
	title = ft_get_user_input("Enter title: ");
	window = mlx_new_window(mlx, 800, 600, title);
	if (window == NULL)
		ft_exit_w_error("errno");
	free (title);
	ft_printf("OS detected: ");
	ft_run_command("uname", envp);
	ft_printf("Initializing GUI...\n");
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}