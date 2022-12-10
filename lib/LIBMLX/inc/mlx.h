/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:37:52 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/09 18:56:12 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx.h for MinilibX in
** 
** Forked and modified rom the subject repo by Charlie Root and Olivier Crouzet
** by Iker Sojo for so_long project (Dec 2022).
** 
** Usage in MacOSX (including apple silicon):
** In order to use the compiled library in MacOSX, compile prgrams including
** 2 frameworks: OpenGL and AppKit. Add the following flags to src compilation:
** 		... -framework OpenGL -framework AppKit
**
*/

#ifndef MLX_H
# define MLX_H

/* Initialize minilibx library functions */
void	*mlx_init();

/* Basic actions
** --------------------------------------------------------------------------*/

/* Create new window */
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);


/* Image stuff
** --------------------------------------------------------------------------*/

void	*mlx_new_image(void *mlx_ptr,int width,int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
							int *size_line, int *endian);
/*
**  endian : useless on macos, client and graphical framework have the same endian
*/
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
								int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);


/* dealing with Events
** --------------------------------------------------------------------------*/

int		mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop (void *mlx_ptr);


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
void	*mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);

int     mlx_mouse_hide();
int     mlx_mouse_show();
int     mlx_mouse_move(void *win_ptr, int x, int y);
int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int 	mlx_do_key_autorepeatoff(void *mlx_ptr);
int 	mlx_do_key_autorepeaton(void *mlx_ptr);
int 	mlx_do_sync(void *mlx_ptr);

#endif
