/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:40:37 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/06 22:10:12 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_move_right(t_data *data)
{
	t_img	*move;

	move = data->imgs;
	mlx_clear_window(data->mlx, data->win);
	ft_first_printmap(data);
	if (data->m > 2)
		ft_move_right2(data);
	else if (data->m == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[6], (move->pl[1]), (move->pl[0]));
		data->m++;
		//usleep(60000);
		return ;
	}
	else if (data->m == 1)
	{
		//ft_printf("Aqui 2\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[7], (move->pl[1]), (move->pl[0]));
		data->m++;
		//usleep(60000);
		return ;
	}
	else if (data->m == 2)
	{
		//ft_printf("Aqui 3\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[8], (move->pl[1]), (move->pl[0]));
		data->m++;
		return ;
		//usleep(60000);
	}
//	usleep(50000);
}

void	ft_move_right2(t_data *data)
{
	if (data->m == 3)
	{
		//ft_printf("Aqui 4\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[9], (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->m++;
		//usleep(60000);
		return ;
	}
	else if (data->m == 4)
	{
		//ft_printf("Aqui 5\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[10], (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->m++;
		//usleep(60000);
		return ;
	}
	else if (data->m == 5)
	{
		//ft_printf("Aqui 6\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[11], (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		data->m = 0;
		//usleep(60000);
		return ;
	}
}
