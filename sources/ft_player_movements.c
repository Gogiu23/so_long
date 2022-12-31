/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:29:09 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/31 05:52:21 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_player_move_right(t_data *data)
{
//	mlx_put_image_to_window(data->mlx, data->win, data->imgs[1].img, \
//			(data->imgs->pl[1] + 50), (data->imgs->pl[0]));
	data->imgs->pl[1] += 2;
	return (0);
}

int	ft_player_move_left(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[1].img, \
			(data->imgs->pl[1] - 50), (data->imgs->pl[0] - 50));

	return (0);
}

//int	ft_player_move_up(t_data *data)
//{
//
//	return (0);
//}
//
//int	ft_player_move_down(t_data *data)
//{
//
//	return (0);
//}
