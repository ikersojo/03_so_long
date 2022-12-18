/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:59 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/18 09:58:48 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/LIBFT/inc/libft.h"
# include "../lib/LIBMLX/inc/mlx.h"
# include <fcntl.h>

// Pixel size of each .xpm file (48 x 48)
# define PX	48

// Key Codes for MacOS
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

// MacOS Events
# define ON_KEYDOWN		2
# define ON_KEYUP 		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

// Assets location
# define IMG_COUNT	4
# define FLOOR	"./assets/img48x48/xpm/floor/grass.xpm"
# define WALL	"./assets/img48x48/xpm/wall/wall.xpm"
# define COLL	"./assets/img48x48/xpm/collectable/coin_4.xpm"
# define PLAYER	"./assets/img48x48/xpm/player/player_10.xpm"


// imgae datatype
typedef struct s_img
{
	void	*content;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

// gui datatype
/* DETAIL ON IMAGES:
img[0]: floor
img[1]: wall
img[2]: coin
img[3]: exit
img[4]: enemy
img[5]: player
*/
typedef struct s_gui
{
	void	*mlx;
	void	*win;
	char	title[40];
	int		width;
	int		height;
	t_img	*img[4];
}			t_gui;

typedef struct s_game
{
	t_gui	*gui;
	int		x_pos;
	int		y_pos;
	int		map_width;
	int		map_height;
	int		steps;
	int		collectables;
}			t_game;

int		ft_on_destroy(int keycode, void *param);
int		ft_on_keydown(int keycode, void *param);
int		ft_on_idle(int keycode, void *param);
void	ft_close_game(t_game *game);
#endif