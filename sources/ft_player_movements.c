/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:29:09 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/08 22:41:51 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_player_move_right(t_data *data)
{
	data->imgs->pl[1] += 8;
//	ft_move_right(data);
//	data->y++;
	return (0);
}

int	ft_player_move_left(t_data *data)
{
	data->imgs->pl[1] -= 8;
	data->y++;
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
