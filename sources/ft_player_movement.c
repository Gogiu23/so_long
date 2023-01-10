/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 23:00:43 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

void	ft_player_move_horitzontal(t_data *data)
{
	t_img	*mov;

	mov = data->imgs;
	if (mov->acm[0] == 2)
		mov->pl[1] += ft_right_collision(data);
	else if (mov->acm[0] == 1)
		mov->pl[1] -= ft_left_collision(data);
}

void	ft_player_jump(t_data *data)
{
	t_img	*jump;

	jump = data->imgs;
	if (jump->acm[0] == 10)
		jump->pl[0] -= JMPX;
}
