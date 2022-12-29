/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player_still.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:09:00 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/29 01:36:38 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void 	ft_player_stop(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->x == 0)
	{
		ft_printf("X1: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->x++;
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 1)
	{
		ft_printf("X2: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (b * 50), (a * 50));
		data->x++;
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 2)
	{
		ft_printf("X3: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (b * 50), (a * 50));
		data->x++;
		return ;
	}
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
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 4)
	{
		ft_printf("X5: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (b * 50), (a * 50));
		data->x++;
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 5)
	{
		ft_printf("X6: %d\n", data->x);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[9].img, (b * 50), (a * 50));
		data->y++;
		data->x++;
		return ;
	}
}

void	ft_player_stop_back(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->y == 1)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (b * 50), (a * 50));
		data->y++;
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->y == 2)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (b * 50), (a * 50));
		data->y++;
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->y == 3)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (b * 50), (a * 50));
		data->y++;
		return ;
	}
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
		return ;
	}
	else if (data->matrix[a][b] == 'P' && data->y == 5)
	{
		ft_printf("X back: %d\n", data->y);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->y = 0;
		data->x = 0;
		return ;
	}
}
