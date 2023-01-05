/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:40:37 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/05 23:44:31 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_move_right(t_data *data)
{
	ft_printf("Entramos aqui\n");
	mlx_clear_window(data->mlx, data->win);
	ft_first_printmap(data);
//	mlx_put_image_to_window(data->mlx, data->win, data->imgs[1].img, \
//			data->imgs->pl[1], data->imgs->pl[0]);
}
