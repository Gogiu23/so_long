/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/26 06:37:18 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	char	*map;
	int		map_height;// altura of the map //
	int		map_width;// anchura del mapa //
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**matrix;
	char	*pic;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		time;
	int		step;
	t_img	*imgs;
}	t_data;
	

void	ft_pixel_push(t_data *data, int x, int y, int color);

// Function in order to get the size of the map //
void	ft_get_map(t_data *data, int fd);
void	ft_get_size_map(t_data *data, int fd, char **argv);

// FUnctions check errors //
void	ft_check_errors(t_data *data);
void	ft_check_size_map(t_data *data);

// Function create doble array in order to store the map //
void	ft_fitoar(t_data *t, int fd);
void	ft_free_stacks_t(t_data *t);

// Function start the game //
void	ft_start_game(t_data *data);

void	ft_print_stack(t_data *t);
int		ft_next_game(int keycode, t_data *data);
void	ft_after_loading(t_data *data);


void	ft_load_images(t_data *data);
void	ft_first_printmap(t_data *data);
void 	ft_second_printmap(t_data *data, int a, int b);
int		ft_wait_time(t_data *data);

// Fucntion to exit the game without leaks //
int		ft_exit_game(int keycode, t_data *data);

#endif
