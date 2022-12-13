/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:10:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/13 06:19:45 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_start_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 1000, 400, "Time machine");
	data->img = mlx_new_image(data->mlx, 1000, 400);
	data->pic = mlx_xpm_file_to_image(data->mlx, "images/image-7start.xpm", \
			&data->img_width, &data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	ft_printf("bpp: %d\n", data->bits_per_pixel);
	ft_printf("line_length: %d\n", data->line_length);
	ft_printf("endian: %d\n", data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
//	mlx_string_put(data->mlx, data->win, 400, 100, 0xFFFF00, "METAUNIVERS");
//	mlx_string_put(data->mlx, data->win, 400, 150, 0xFF4500, "1 NEW GAME");
//	mlx_string_put(data->mlx, data->win, 400, 180, 0xFF4500, "2 EXIT GAME");
////	mlx_destroy_image(data->mlx, data->win);
	mlx_key_hook(data->win, ft_close_game, &data);
//	mlx_key_hook(data->win, ft_next_game, &data);
}

int	ft_close_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
	}
	return (0);
}

int	ft_next_game(int keycode, t_data *data)
{
	if (keycode == 18)
	{
		int	t;

		t = 1;
		ft_printf("breakpoint%d\n", t++);
//		mlx_destroy_image(data->mlx, data->img);
		ft_printf("breakpoint%d\n", t++);
		data->img2 = mlx_new_image(data->mlx, 1000, 400);
		ft_printf("breakpoint%d\n", t++);
//		data->pic2 = mlx_xpm_file_to_image(data->mlx, "images/image-7start.xpm", &data->img_width, &data->img_height);
		ft_printf("breakpoint%d\n", t++);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
		ft_printf("breakpoint%d\n", t++);
//		mlx_put_image_to_window(data->mlx, data->win, data->pic2, data->x, data->y);
		ft_printf("breakpoint%d\n", t++);
//		mlx_loop(data->mlx);
	}
	return (0);
}
