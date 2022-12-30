/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:25 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/30 02:00:01 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_first_printmap(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
						data->imgs[0].img, (b * 50), (a * 50));
			ft_player_stop(data, a, b);
			usleep(250);
			if (data->x == 6)
				ft_player_stop_back(data, a, b);
			ft_second_printmap(data, a, b);
			b++;
		}
		a++;
	}
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF4550, "Esc = exit game");
	return (0);
}

void 	ft_second_printmap(t_data *data, int a, int b)
{	
	if (data->matrix[a][b] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[3].img, (b * 50), (a * 50));
	else if (data->matrix[a][b] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[4].img, (b * 50), (a * 50));
	if (data->matrix[a][b] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[5].img, (b * 50), (a * 50));
}
