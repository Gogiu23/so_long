/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 04:38:49 by gdominic         ###   ########.fr       */
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
	int		bpp;
	int		line_length;
	int		endianl;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	char	*map;
	int		map_size;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**matrix;
	char	*pic;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	t_img	*imgs;
}	t_data;
	

void	ft_pixel_push(t_data *data, int x, int y, int color);

// Function in order to get the size of the map //
void	ft_get_map(t_data *data, int fd);
void	ft_get_size_map(t_data *data, int fd, char **argv);

// FUnctions check errors //
void	ft_check_errors(t_data *data);
void	ft_check_size_map(t_data *data);

void	ft_fitoar(t_data *t, int fd);
void	ft_free_stacks_t(t_data *t);
void	ft_start_game(t_data *data);
int		ft_close_game(int keycode, t_data *data);
void	ft_print_stack(t_data *t);
int		ft_next_game(int keycode, t_data *data);

#endif
