/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:59 by isojo-go          #+#    #+#             */
/*   Updated: 2022/12/30 13:10:30 by isojo-go         ###   ########.fr       */
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
# define IMG_COUNT	18
# define FLOOR		"./assets/img48x48/xpm/floor/grass.xpm"
# define WALL		"./assets/img48x48/xpm/wall/wall.xpm"
# define COLL		"./assets/img48x48/xpm/collectable/coin_3.xpm"
# define PLAYER_U	"./assets/img48x48/xpm/player/player_up.xpm"
# define PLAYER_D	"./assets/img48x48/xpm/player/player_down.xpm"
# define PLAYER_L	"./assets/img48x48/xpm/player/player_left.xpm"
# define PLAYER_R	"./assets/img48x48/xpm/player/player_right.xpm"
# define EXIT_C		"./assets/img48x48/xpm/exit/exit_c.xpm"
# define EXIT_O		"./assets/img48x48/xpm/exit/exit_o.xpm"
# define COLL_A_1	"./assets/img48x48/xpm/collectable/coin_1.xpm"
# define COLL_A_2	"./assets/img48x48/xpm/collectable/coin_2.xpm"
# define COLL_A_3	"./assets/img48x48/xpm/collectable/coin_3.xpm"
# define COLL_A_4	"./assets/img48x48/xpm/collectable/coin_4.xpm"
# define COLL_A_5	"./assets/img48x48/xpm/collectable/coin_5.xpm"
# define COLL_A_6	"./assets/img48x48/xpm/collectable/coin_6.xpm"
# define COLL_A_7	"./assets/img48x48/xpm/collectable/coin_7.xpm"
# define COLL_A_8	"./assets/img48x48/xpm/collectable/coin_8.xpm"
# define ENEMY		"./assets/img48x48/xpm/enemy/enemy.xpm"

// required to avoid max arg limitation on map floodfill check
typedef struct s_size
{
	int	w;
	int	h;
}		t_size;

// store all information about the window
typedef struct s_gui
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*img[IMG_COUNT];
}			t_gui;

// store all information about the map
typedef struct s_map
{
	char	**grid;
	int		w;
	int		h;
	int		max_coll;
}			t_map;

// store all informatino about the map
typedef struct s_game
{
	t_gui	*gui;
	t_map	*map;
	int		x_pos;
	int		y_pos;
	int		steps;
	int		collectables;
	int		x_exit;
	int		y_exit;
	int		frame;
}			t_game;

/*------POSSIBLE EVENTS------*/
int		ft_on_destroy(int keycode, void *param);
int		ft_on_keydown(int keycode, void *param);
int		ft_on_idle(int keycode, void *param);
void	ft_close_game(t_game *game);

/*------PLAYER MOVEMENTS------*/
void	ft_move(t_game *game, int x, int y, int player_img);

/*------MAP CHECKS------*/
int		ft_check_map(char *str, int *width, int *height, int *coll);
int		ft_check_rect(char *str, int *width, int *height);
int		ft_check_chars(char *str, int *w, int *h, int *coll);
char	**ft_gen_map_grid(char *map_file, int w, int h);
int		ft_feasibility(char *str, int width, int height);
char	*ft_allowed_c(void);

/*------PRINT to SCREEN------*/
t_game	*ft_initialize_game(char *map_file);
void	ft_print_map(t_game *game);
void	ft_print_counters(t_game *game);
void	ft_turn_coin(t_game *game);

#endif
