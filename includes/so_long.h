/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/08 20:50:59 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	char	**matrix;
	char	*pic;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}	t_data;

void	ft_pixel_push(t_data *data, int x, int y, int color);
int		loop_hook(t_data *data);
void	ft_square(t_data *data);
void	ft_triangle(t_data *data);
char	ft_get_map(char **argv);
void	ft_fitoar(t_data *t, int fd);
void	ft_free_stacks_t(t_data *t);
void	ft_print_stack(t_data *t);

#endif
