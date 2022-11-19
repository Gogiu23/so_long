/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/19 22:45:40 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	loop_hook(t_data *data)
{
	if (data->x < 100)
	{
	ft_pixel_push(data, data->x, 5, 0x00FF0001);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, 0);
	data->x++;
	usleep(50000);
	}
	return (0);
}

int	main(void)
{
	t_data 	data;
//	int		x = 5;

	data.x = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1240, 720, "Hello world");
	data.img = mlx_new_image(data.mlx, 1240, 720);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
//	while (x < 100)
//	{
//		ft_pixel_push(&img, x, 5, 0x00FF0001);
		mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
//		x++;
//		sleep(1);
//	}
//	while (x < 100)
//	{
//		mlx_put_image_to_window(mlx, mlx_win, img.img, x, 0);
//		x++;
//	}
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
