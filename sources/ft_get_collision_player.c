/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_collision_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:32 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 15:51:32 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_right_collision(t_data *data)
{
	t_img	*c;
	int		distance;
	char	**map;

	c = data->imgs;
	map = data->matrix;
	if (map[(c->bl[1] + HTX + ETX) / PXS][c->bl[0] / PXS + 1] == '1' || \
			map[(c->br[1]) / PXS][(c->br[0]) / PXS + 1] == '1')
	{
		if (map[(c->bl[1] + HTX) / PXS][(c->bl[0] - HTX) / PXS] == '1' || \
				map[c->br[1] / PXS][(c->br[0] - HTX) / PXS] == '1')
			return (-(HTX + 10));
		distance = PXS + (PXS * ((c->bl[0] - HTX) / PXS) - c->bl[0]) - 1;
		if (distance > MVM)
			return (MVM);
		return (distance);
	}
	if (map[c->bl[1] + HTX +ETX / PXS][(c->bl[0] - HTX + ETX) / PXS] == '1' || \
		map[c->br[1] / PXS][(c->br[0] - HTX + ETX) / PXS] == '1')
		return (-(HTX + ETX + 5));
	return (MVM);
}

int	ft_left_collision(t_data *data)
{
	t_img	*c;
	int		distance;
	char	**map;

	c = data->imgs;
	map = data->matrix;
	distance = 0;
	return (MVM);
}
