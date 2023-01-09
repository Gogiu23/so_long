/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:10:57 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 19:33:44 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->step++;
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->pic = mlx_png_file_to_image(data->mlx, \
			"images/start_game/start_page.png", \
			&data->img_width, &data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
	mlx_hook(data->win, 2, 0, ft_next_game, data);
	mlx_hook(data->win, 17, 0, (void *)exit, 0);
	mlx_loop_hook(data->mlx, ft_wait_time, data);
	mlx_loop(data->mlx);
}

int	ft_get_player_position(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == 'P')
			{
				data->imgs = ft_calloc((sizeof (t_img) * 1), 1);
				data->imgs->pl[0] = (a * 50);
				data->imgs->pl[1] = (b * 50) - 1;
				return (1);
			}
			b++;
		}
		a++;
	}
	data->imgs->lpl[1] = data->imgs->pl[1];
	return (0);
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
		data->pic = mlx_png_file_to_image(data->mlx, \
				"images/start_game/level1.png", \
				&data->img_width, &data->img_height);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
		mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
	}
	return (0);
}

int	ft_wait_time(t_data *data)
{
	if (data->step == 2)
		data->time++;
	if (data->time >= 20000)
		ft_after_loading(data);
	return (0);
}
