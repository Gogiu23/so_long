/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:09:41 by gdominic          #+#    #+#             */
/*   Updated: 2023/04/23 06:42:36 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	*ft_get_img(t_data *data)
{
	static	int	nr;

	if (nr < 4) 
		nr++;
	else
		nr = 0;
	return (data->cll_img[nr]);
}

static	void	ft_search_item(t_data *data)
{
	int		a;
	int		b;
//	t_img	*item;

	a = 0;
//	item = data->imgs;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == 'C')
				ft_put_img(data, ft_get_img(data), b * PXS, a * PXS);
			b++;
		}
		a++;
	}
}

void	ft_print_collectable(t_data *data)
{
	ft_search_item(data);
}
