/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:25 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/06 21:56:15 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_first_printmap(t_data *data)
{
	data->a = 0;
	while (data->matrix[data->a])
	{
		data->b = 0;
		while (data->matrix[data->a][data->b])
		{
			if (data->matrix[data->a][data->b] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
						data->wll_img[0], (data->b * 50), (data->a * 50));
//			exit (0);
//			ft_player_stop(data);
//			usleep(150);
//			if (data->x == 6)
//				ft_player_stop_back(data);
			ft_second_printmap(data);
			data->b++;
		}
		data->a++;
	}
	ft_print_collectable(data);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF4550, "Esc = exit game");
	return (0);
}

void 	ft_second_printmap(t_data *data)
{	
	if (data->matrix[data->a][data->b] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->gr_img[0], (data->b * 50), (data->a * 50));
	else if (data->matrix[data->a][data->b] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->wll_img[0], (data->b * 50), (data->a * 50));
	else if (data->matrix[data->a][data->b] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->ext_img[0], (data->b * 50), (data->a * 50));
	else if (data->matrix[data->a][data->b] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->gr_img[0], data->b * 50, data->a * 50);
}
