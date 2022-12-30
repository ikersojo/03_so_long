# 03_so_long

# Introduction
This project will make you create a small 2D game. It is designed to make you work with textures and sprites. And of course, basic elements of playability as well.

The mandatory part is focused on collecting all collectables of a map, and then exiting the map to finish the game. The bonus part adds enemies to the mix.
All graphical work is condicted using the library minilibx (provided in the subject).

## Compilation
The programme will generate all the object files of the compiled c files in the obj directory and the final executable on the bin folder.

| Rule | Function |
| - | - |
| ``make`` | Generates an object file for each .c and the so_long executable binnary file |
| ``make clean`` | Deletes all object files |
| ``make fclean`` | Deletes the object files and the executables / libraries |
| ``make re`` |``fclean`` + ``make`` |
| ``make bonus`` | Allows enemies on the maps |

## Valid maps
A set of maps os porvided in the ./maps/ folder. NOte that one key aspect of the project is to be able to validate th emaps before launching the game.

<img  width="300" src="https://github.com/ikersojo/03_so_long/blob/main/doc/imgs/map_file.png\?raw\=true">

| Char | Description |
| - | - |
| 1 | Wall (player cannot go through them) |
| 0 | free space (movement allowed) |
| C | Collectable |
| E | Exit |
| P | Player starting position |
| Z | Enemy (only in bonus) |

## Example:
Execued as:
```
./bin/so_long ./maps/valid/valid_1.ber
```
The console will output the checks of the map: rectangular shape, allowed characters only and game feasibility (i.e. if it can be completed or not).
<img  width="300" src="https://github.com/ikersojo/03_so_long/blob/main/doc/imgs/example_console.png\?raw\=true">
<img  width="300" src="https://github.com/ikersojo/03_so_long/blob/main/doc/imgs/example_game.png\?raw\=true">

# Minilibx
The programme includes, compiles and uses minilibx library. There are multiple versions (more updated, robust and featured) on the internet, but follwoing 42 staff recommendation, the library provided in the subject has been used. Teh documentation of such libraries is helful to understand the behaviour of the minilibx.
The man pages of the official library can be found here:
- [man_mlx](https://github.com/ikersojo/03_so_long/blob/main/lib/LIBMLX/doc/man/man_mlx.md)
- [man_mlx_loop](https://github.com/ikersojo/03_so_long/blob/main/lib/LIBMLX/doc/man/man_mlx_loop.md)
- [man_mlx_new_image](https://github.com/ikersojo/03_so_long/blob/main/lib/LIBMLX/doc/man/man_mlx_new_image.md)
- [man_mlx_new_window](https://github.com/ikersojo/03_so_long/blob/main/lib/LIBMLX/doc/man/man_mlx_new_window.md)
- [man_mlx_pixel_put](https://github.com/ikersojo/03_so_long/blob/main/lib/LIBMLX/doc/man/man_mlx_pixel_put.md)

# Layout and sequence of the program
All the code can be found on the ./src/ folder. The steps and names are self explanatory

# Bonus
The bonus program adds enemies to the map (defined with letter 'Z').
Note that compiled as "make" will not allow 'Z' characters in th emap, but compiled with "make bonus" it will, and represent them in the game.

# Score
<img  width="300" src="https://github.com/ikersojo/03_so_long/blob/main/doc/imgs/score.png\?raw\=true">

# Resources / further info
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

https://harm-smits.github.io/42docs/libs/minilibx

https://github.com/S-LucasSerrano/miniLibX_sample