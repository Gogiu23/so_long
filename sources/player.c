/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:05:27 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/14 16:09:51 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"

int	*ft_get_pl(t_data *data)
{
	t_img	*split;

	split = data->imgs;
	if (split->jumping == 0)
	{
		if (split->direction == 0)
			ft_get_sprite_right(data);
		else 
			ft_get_sprite_left(data);
	}
	else if (split->jumping != 0 || split->velocity > 0)
		ft_get_sprite_jump(data);
	if (ft_down_collision(data) != 0)
		ft_get_sprite_jump(data);
	return (data->pl_img[split->sp]);
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
