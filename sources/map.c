/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:10:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 05:03:27 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_start_game(t_data *data)
{
	int count = 0;
//	data->mlx = mlx_init();
	ft_printf("breakpoint: %d\n", count++);
	data->win = mlx_new_window(data->mlx, 1000, 400, "Time machine");
	data->img = mlx_new_image(data->mlx, 1000, 400);
	data->pic = mlx_xpm_file_to_image(data->mlx, "images/image-7start.xpm", \
			&data->img_width, &data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
	mlx_string_put(data->mlx, data->win, 400, 100, 0xFFFF00, "METAUNIVERS");
	mlx_string_put(data->mlx, data->win, 400, 150, 0xFF4500, "1 NEW GAME");
	mlx_string_put(data->mlx, data->win, 400, 180, 0xFF4500, "2 EXIT GAME");
//	mlx_hook(data->win, 2, 0, ft_next_game, &data);
//	mlx_loop(data->mlx);
}

int	ft_next_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == 18)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 1000, 400);
		data->pic = mlx_xpm_file_to_image(data->mlx, "images/Frame-1loadingtest.xpm", \
				&data->img_width, &data->img_height);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
		mlx_put_image_to_window(data->mlx, data->win, data->pic, 350, 100);
		sleep(1);
		mlx_clear_window(data->mlx, data->win);
	}
	return (0);
}
