/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:11:50 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/07 19:47:34 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_print_env(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_print_wall(data);
	ft_print_background(data);
	ft_print_exit(data);
	ft_print_collectable(data);
	return (1);
}

void	ft_print_player(t_data *data)
{
	t_img	*move;

	move = data->imgs;
	mlx_clear_window(data->mlx, data->win);
//	exit (0);
	if (data->x > 2)
		ft_print_player2(data);
	else if (data->x == 0)
	{
		//ft_printf("Aqui 1\n");
		//mlx_clear_window(data->mlx, data->win);
		//ft_first_printmap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
				data->pl_img[0], (move->pl[1]), (move->pl[0]));
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
				data->pl_img[1], (move->pl[1]), (move->pl[0]));
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
				data->pl_img[2], (move->pl[1]), (move->pl[0]));
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
				data->pl_img[3], (data->imgs->pl[1]), (data->imgs->pl[0]));
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
				data->pl_img[4], (data->imgs->pl[1]), (data->imgs->pl[0]));
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
				data->pl_img[5], (data->imgs->pl[1]), (data->imgs->pl[0]));
		data->y++;
		data->x = 0;
		//usleep(60000);
		return ;
	}
}
