/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:10:57 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/09 06:18:15 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_start_game(t_data *data)
{
	char	*relative_path;

	relative_path = "images/image-1.xpm";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1240, 720, "Time machine");
	data->img = mlx_new_image(data->mlx, 1240, 720);
	data->pic = mlx_xpm_file_to_image(data->mlx, relative_path, &data->img_width, \
			&data->img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->pic, data->x, data->y);
	mlx_hook(data->win, 2, 0, ft_close_game, &data); 
	mlx_loop(data->mlx);
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
