/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:53:13 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/19 06:08:18 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_pixel_push(t_data *data, int x, int y, int color)
{
	char	*width;

	width = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)width = color;
}
