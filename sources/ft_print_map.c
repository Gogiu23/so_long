/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:25 by gdominic          #+#    #+#             */
/*   Updated: 2023/02/02 16:43:57 by gdominic         ###   ########.fr       */
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
	mlx_string_put(data->mlx, data->win, 20, 20, 0xFF4550, "Esc = exit game");
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
//			ft_printf("data->matrix[%d][%d]: %c\n", a, b, data->matrix[a][b]);
			if (data->matrix[a][b] == 'P' || data->matrix[a][b] == 'C' \
					|| data->matrix[a][b] == 'E' || data->matrix[a][b] == '0')
				ft_put_img(data, data->gr_img[0], b * PXS, a * PXS);
			else
				ft_put_img(data, data->wll_img[0], b * PXS, a * PXS);
			b++;
		}
		a++;
	}
//	usleep(500);
}

void	ft_print_background_init(t_data *data)
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
//	usleep(500);
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
