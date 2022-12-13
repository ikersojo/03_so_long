/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:32:20 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/13 09:46:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/LIBFT/inc/libft.h"
#include "../lib/LIBMLX/inc/mlx.h"
#include <fcntl.h>

// Key Codes for MacOS
#define KEY_ESC		53
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_R		15
#define KEY_Q		12
#define KEY_UP		126
#define KEY_DOWN	125
#define KEY_LEFT	123
#define KEY_RIGHT	124

// pointer to window
typedef struct s_win
{
	void	*win_ptr;
	char	*title; // opcion de usar [80] para evitar el malloc y el free
	int		width;
	int		height;
}			t_win;

// pointer to image
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp; // bits_per_pixel
	int		line_len;
	int		endian; // 0 little endian: ordenado de más a menos (MacOS) -> ordena la info al reves! (blue, green, red, alpha)
}			t_img;

// aux function 1
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	my_rectangle(t_img *img, int width, int height, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

// main function
int	main(int argc, char **argv, char **envp)
{
	void	*mlx;
	t_win	*win;
	t_img	*img;

	(void)argc;
	(void)argv;

	mlx = mlx_init();
	if (mlx == NULL)
		ft_exit_w_error("errno");
	win = (t_win *)malloc(sizeof(t_win));
	if (win == NULL)
		ft_exit_w_error("errno");
	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		ft_exit_w_error("errno");

	(*win).title = ft_get_user_input("Enter title: "); // to be modified (strdup?)
	win->width = 1280; // to be modified with map
	win->height = 800; // to be modified with map
	win->win_ptr = mlx_new_window(mlx, win->width, win->height, win->title);
	if (win->win_ptr == NULL)
		ft_exit_w_error("errno");

	img->img_ptr = mlx_new_image(mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);

	//DEBUG:
	ft_printf("win: %p\nwin_ptr: %p\ntitle: %s\nwidth: %d\nheight: %d\n\n", win, win->win_ptr, win->title, win->width, win->height);
	ft_printf("img: %p\nimg_ptr: %p\naddr: %s(%p)\nbpp: %d\nline_len: %d\nendian: %d\n\n", img, img->img_ptr, img->addr, img->addr, img->bpp, img->line_len, img->endian);

	// my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	my_rectangle(img, win->width, win->height, 0x00FF0000);
	mlx_put_image_to_window(mlx, win->win_ptr, img->img_ptr, 0, 0);
	my_rectangle(img, 50, 50, 0x0000FF00);
	mlx_put_image_to_window(mlx, win->win_ptr, img->img_ptr, 100, 100);







	ft_printf("OS detected: ");
	ft_run_command("uname", envp);
	ft_printf("Initializing GUI...\n");

	free (win->title);
	mlx_loop(mlx);

	// para salir borrar ventana
	mlx_destroy_window(mlx, win->win_ptr);
	return (EXIT_SUCCESS);
}
