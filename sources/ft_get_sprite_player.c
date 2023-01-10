/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sprite_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:43:07 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 23:59:22 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_get_sprite_right(t_data *data)
{
	t_img	*sprite;

	sprite = data->imgs;
	if (data->imgs->acm[0] == 2)
	{
		if (sprite->sp < 15 && sprite->sp > 5)
			sprite->sp++;
		else
			sprite->sp = 6;
		return (sprite->sp);
	}
	else
		if (sprite->sp < 5)
			sprite->sp++;
		else
			sprite->sp = 0;
	return (sprite->sp);
}

int	ft_get_sprite_left(t_data *data)
{
	t_img	*sprite;

	sprite = data->imgs;
	if (data->imgs->acm[0] == 1)
	{
		if (sprite->sp < 29 && sprite->sp > 22)
			sprite->sp++;
		else
			sprite->sp = 23;
		return (sprite->sp);
	}
	else
		if (sprite->sp < 21)
			sprite->sp++;
		else
			sprite->sp = 16;
	return (sprite->sp);
}
