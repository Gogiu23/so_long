/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:15:10 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/20 20:20:33 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_square(t_data *data)
{
	while (data->x < 100)
	{
		data->y = 0;
		while (data->y < 100)
		{
			ft_pixel_push(data, data->x, data->y, 0x00FF00000);
			mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 5);
			data->y++;
		}
		data->x++;
	}
//	while (data->x < 100)
//	{
//		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
//		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//		data->x++;
//	}
//	while (data->y < 100)
//	{
//		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
//		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//		data->y++;
//	}
//	while (data->x > 5)
//	{
//		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
//		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//		data->x--;
//	}
//	while (data->y > 5)
//	{
//		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
//		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//		data->y--;
//	}
	mlx_loop(data->mlx);
}

void	ft_triangle(t_data *data)
{
	while (data->x < 100 && data->y < 100)
	{
		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		data->x++;
		data->y++;
	}
	while (data->x > 5)
	{
		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 5, 5);
		data->x--;
	}
	while (data->y > 5)
	{
		ft_pixel_push(data, data->x, data->y, 0x00FF00000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		data->y--;
	}
	mlx_loop(data->mlx);
}
