/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:25 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/07 19:05:58 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_print_wall(t_data *data)
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
				ft_put_img(data, data->wll_img[0], b * PXS, a * PXS);
			b++;
		}
		a++;
	}
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF4550, "Esc = exit game");
}

void	ft_print_background(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == '0' || data->matrix[a][b] == 'P' \
					|| data->matrix[a][b] == 'C' || data->matrix[a][b] == 'E')
				ft_put_img(data, data->gr_img[0], b * PXS, a * PXS);
			b++;
		}
		a++;
	}
}

void	ft_print_exit(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == 'E')
				ft_put_img(data, data->ext_img[0], b * PXS, a * PXS);
			b++;
		}
		a++;
	}
}
