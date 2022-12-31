/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:11:50 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/31 15:26:45 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_print_player(t_data *data)
{
	data->x = 5;
	while (data->x > 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgs[data->x].img, \
				data->imgs->pl[1], data->imgs->pl[0]);
		data->x--;
	}
	return (0);
}
