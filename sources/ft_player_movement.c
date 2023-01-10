/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/10 23:51:38 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

void	ft_player_move_horitzontal(t_data *data)
{
	t_img	*mov;

	mov = data->imgs;
	if (mov->acm[0] == 2)
		mov->pl[0] += ft_right_collision(data);
	else if (mov->acm[0] == 1)
		mov->pl[0] -= ft_left_collision(data);
}

void	ft_player_jump(t_data *data)
{
	t_img	*jump;

	jump = data->imgs;
	if ((jump->acm[0] == 10 || jump->acm[1] == 10) && ft_top_collision(data) == 0 \
			&& jump->jumping == 0)
		jump->jumping = 4;
	else if (jump->jumping > 0)
	{
		jump->pl[1] -= ft_top_collision(data);
		jump->jumping--;
	}
}

void	ft_player_gravity(t_data *data)
{
	t_img	*gravity;

	gravity = data->imgs;
	if (ft_top_collision(data) > 0)
		gravity->pl[1] += ft_top_collision(data);
}
