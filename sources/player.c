/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:05:27 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/10 22:03:45 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	*ft_get_pl(t_data *data)
{
	t_img	*split;

	split = data->imgs;
	if (split->direction == 0)
	{
		ft_get_sprite_right(data);
		return (data->pl_img[split->sp]);
	}
	else
	{
		ft_get_sprite_left(data);
		return (data->pl_img[split->sp]);
	}
	return (0);
}

static	void	ft_search_player(t_data *data)
{
	ft_put_img(data, ft_get_pl(data), data->imgs->pl[0], data->imgs->pl[1]);
}

void	ft_print_player(t_data *data)
{
	ft_player_move_horitzontal(data);
	ft_player_gravity(data);
	ft_player_jump(data);
	ft_search_player(data);
}
