/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:10:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/26 06:32:25 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_start_game(t_data *data)
{
	data->step++;
	data->win = mlx_new_window(data->mlx, 1000, 400, "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, 1000, 400);
	data->pic = mlx_xpm_file_to_image(data->mlx, "images/start_page.xpm", \
			&data->img_width, &data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
}

int	ft_next_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_free_stacks_t(data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == 36)
	{
		data->step++;
		mlx_clear_window(data->mlx, data->win);
//		mlx_destroy_image(data->mlx, data->img);
//		data->img = mlx_new_image(data->mlx, 1000, 400);
		data->pic = mlx_xpm_file_to_image(data->mlx, "images/Slice-1newlev1.xpm", \
				&data->img_width, &data->img_height);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
		mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
	}
	return (0);
}

int	ft_wait_time(t_data *data)
{
//	ft_printf("data->time: %d\n", data->time);
//	ft_printf("data-step: %d\n", data->step);
	if (data->step == 2)
		data->time++;
	if (data->time >= 20000)
		ft_after_loading(data);
	return (0);
}
