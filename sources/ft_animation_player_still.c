/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_player_still.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:09:00 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/31 05:46:58 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_player_stop(t_data *data)
{
	if (data->matrix[data->a][data->b] == 'P' && data->x == 0)
	{
//		data->imgs->pl[0] = data->a * 50;
//		data->imgs->pl[1] = data->b * 50;
		ft_printf("Valor de data->b: %d\n", data->b);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->x == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->x == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		return ;
	}
	ft_player_stop_second(data);
}

void	ft_player_stop_second(t_data *data)
{
	if (data->matrix[data->a][data->b] == 'P' && data->x == 3)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->x == 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->x == 5)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[9].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		data->x++;
		return ;
	}
}

void	ft_player_stop_back(t_data *data)
{
	if (data->matrix[data->a][data->b] == 'P' && data->y == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->y == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->y == 3)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[6].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		return ;
	}
	ft_player_stop_back_second(data);
}

void	ft_player_stop_back_second(t_data *data)
{
	if (data->matrix[data->a][data->b] == 'P' && data->y == 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		return ;
	}
	else if (data->matrix[data->a][data->b] == 'P' && data->y == 5)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y = 0;
		data->x = 0;
		return ;
	}
}
