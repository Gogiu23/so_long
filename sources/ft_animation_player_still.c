/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player_still.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:09:00 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/28 20:42:21 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void 	ft_player_stop(t_data *data, int a, int b)
{
	if (data->y > 0)
		ft_player_stop_back(data, a, b);
	if (data->matrix[a][b] == 'P' && data->x == 0)
	{
		ft_printf("X1: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 1)
	{
		ft_printf("X2: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 2)
	{
		ft_printf("X3: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (b * 50), (a * 50));
		data->x++;
	}
	//usleep(200);
	ft_player_stop_second(data, a, b);
}

void	ft_player_stop_second(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->x == 3)
	{
		ft_printf("X4: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 4)
	{
		ft_printf("X5: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 5)
	{
		ft_printf("X6: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[9].img, (b * 50), (a * 50));
//		data->x = 0;
		data->y++;
		data->x++;
//		exit (0);
	}
	usleep(20000);
	if (data->y > 0)
		ft_player_stop_back(data, a, b);
}

void	ft_player_stop_back(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->y == 1)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (b * 50), (a * 50));
		data->y++;
	}
	else if (data->matrix[a][b] == 'P' && data->y == 2)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (b * 50), (a * 50));
		data->y++;
//		exit (0);
	}
	else if (data->matrix[a][b] == 'P' && data->y == 3)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (b * 50), (a * 50));
		data->y++;
	}
	//usleep(200);
	ft_player_stop_back_second(data, a, b);
}

void	ft_player_stop_back_second(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->y == 4)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (b * 50), (a * 50));
		data->y++;
//		exit (0);
	}
	else if (data->matrix[a][b] == 'P' && data->y == 5)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
//		data->y++;
		data->y = 0;
		data->x = 0;
//		exit (0);
	}
//	else if (data->matrix[a][b] == 'P' && data->y == 6)
//	{
//		ft_printf("X back: %d\n", data->y);
//		mlx_put_image_to_window(data->mlx, data->win, \
//				data->imgs[1].img, (b * 50), (a * 50));
//	}
	//usleep(200);
}
