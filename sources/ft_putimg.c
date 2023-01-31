/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:45:29 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/31 18:57:12 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

void	ft_put_img(t_data *data, void *img, int a, int b)
{
	if (a < -PXS || b < -PXS || a > WINDOW_WIDTH || b > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, img, a, b);
}
