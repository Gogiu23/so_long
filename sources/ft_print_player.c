/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:11:50 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/05 03:27:15 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_print_env(t_data *data)
{
	if (data->y != 0)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_first_printmap(data);
		data->y = 0;
	}
	ft_print_player(data);
	usleep(50000);
	return (0);
}

//int	ft_wait_time2(t_data *data)
//{
//	ft_printf("data->step: %d\n", data->step);
//	if (data->step == 2)
//		data->time++;
////	if (data->time >= 80)
////		ft_print_player(data);
//	return (0);
//}
void	ft_print_player(t_data *data)
{
	t_img	*move;

	move = data->imgs;
	mlx_clear_window(data->mlx, data->win);
	ft_first_printmap(data);
	if (data->x > 2)
		ft_print_player2(data);
	else if (data->x == 0)
	{
		//ft_printf("Aqui 1\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				move[1].img, (move->pl[1]), (move->pl[0]));
		data->x++;
		//usleep(60000);
		return ;
	}
	else if (data->x == 1)
	{
		//ft_printf("Aqui 2\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				move[2].img, (move->pl[1]), (move->pl[0]));
		data->x++;
		//usleep(60000);
		return ;
	}
	else if (data->x == 2)
	{
		//ft_printf("Aqui 3\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				move[6].img, (move->pl[1]), (move->pl[0]));
		data->x++;
		return ;
		//usleep(60000);
	}
//	usleep(50000);
}

void	ft_print_player2(t_data *data)
{
	if (data->x == 3)
	{
		//ft_printf("Aqui 4\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[7].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		//usleep(60000);
		return ;
	}
	else if (data->x == 4)
	{
		//ft_printf("Aqui 5\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[8].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->x++;
		//usleep(60000);
		return ;
	}
	else if (data->x == 5)
	{
		//ft_printf("Aqui 6\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[9].img, (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		data->x = 0;
		//usleep(60000);
		return ;
	}
}
