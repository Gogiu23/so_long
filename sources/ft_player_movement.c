/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:16:07 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/31 18:49:24 by gdominic         ###   ########.fr       */
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
	if ((jump->acm[0] == 10 || jump->acm[1] == 10) && ft_down_collision(data) == 0 \
			&& jump->jumping == 0)
		jump->jumping = 4;
	else if (jump->jumping > 0)
	{
		jump->pl[1] -= ft_top_collision(data);
		jump->jumping--;
//		usleep(6000);
	}
}

void	ft_player_gravity(t_data *data)
{
	t_img	*gravity;

	gravity = data->imgs;
//	ft_printf("data->matrix: %c\n", data->matrix[(gravity->tr[1]) / PXS +1][(gravity->tr[0] + HTX) / PXS]);
//	ft_printf("gravity->tr[1]/PSX + 1: %d\n", (gravity->tr[1])/PXS+1);
//	ft_printf("gravity->tr[0] + HTX / PXS: %d\n", (gravity->tr[0] + HTX) / PXS);
//	ft_printf("tl[x]: %d\ttl[y]: %d\n", gravity->tl[0], gravity->tl[1]);
//	ft_printf("tr[x]: %d\ttr[y]: %d\n", gravity->tr[0], gravity->tr[1]);
	if (gravity->acm[0] != 4 && gravity->jumping == 0)
		gravity->pl[1] += ft_down_collision(data);
}
