/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_collision_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:32 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/12 10:18:15 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_right_collision(t_data *data)
{
	int		distance;
	t_img	*c;
	char	**map;

   	c = data->imgs;
   	map = data->matrix;
    if (map[(c->bl[1] + HTX + ETX) / PXS][(c->bl[0]) / PXS + 1] == '1' || \
			map[(c->br[1]) / PXS][(c->br[0]) / PXS + 1] == '1')
    {
		if (map[(c->bl[1] + HTX) / PXS][(c->bl[0] - HTX) / PXS] == '1' || \
				map[c->br[1] / PXS][(c->br[0] - HTX) / PXS] == '1')
			return (-(HTX + 10));
		distance = PXS + (PXS * ((c->bl[0]) / PXS) - c->bl[0]) - 1;
		if (distance > MVM)
			return (MVM);
		return (distance);
    }
    if (map[(c->bl[1] + HTX + ETX) / PXS][(c->bl[0] - HTX + ETX) / PXS] == '1' || \
			map[c->br[1] / PXS][(c->br[0] - HTX + ETX) / PXS] == '1')
         return (-(HTX + ETX + 5));
     return (MVM);
}

int	ft_left_collision(t_data *data)
{
	int		distance;
	t_img	*c;
	char	**map;

	c = data->imgs;
	map = data->matrix;
	if (map[(c->tl[1] + HTX + ETX) / PXS][(c->tl[0]) / PXS -1] == '1' ||
	map[(c->tr[1]) / PXS][(c->tr[0]) / PXS -1] == '1')
	{
		if (map[(c->tl[1] + HTX) / PXS][(c->tl[0] + HTX) / PXS] == '1' ||
		map[c->tr[1] / PXS][(c->tr[0] + HTX) / PXS] == '1')
			return (-(HTX + 10));
		distance = c->tl[0] - (PXS * ((c->tl[0]) / PXS));
		if (distance > MVM)
			return (MVM);
		return (distance);
	}
	if (map[(c->tl[1] + HTX + ETX) / PXS][(c->tl[0] + HTX + ETX) / PXS] == '1' ||
	map[c->tr[1] / PXS][(c->tr[0] + HTX + ETX) / PXS] == '1')
		return (-(HTX + ETX + 5));
	return (MVM);
}

int	ft_down_collision(t_data *data)
{
	 int	distance;
	 t_img	*gravity;
	 char	**map;
	
	 gravity = data->imgs;
	 map = data->matrix;
	 if (map[(gravity->tr[1]) / PXS +1][(gravity->tr[0] + HTX) / PXS] == '1' ||
	 map[(gravity->br[1]) / PXS +1][(gravity->br[0] - HTX) / PXS] == '1')
	 {
		 gravity->velocity = 0;
	     distance = (PXS * ((gravity->tr[1]) / PXS + 1)) - gravity->tr[1] -1;
	     if (distance > HTX + ETX)
	         return (GVX);
	     return (distance);
	 }
	 return (gravity->velocity += GVX);
}

int	ft_top_collision(t_data *data)
{
	int		distance;
	t_img	*jump;
	char	**map;

	jump = data->imgs;
	map = data->matrix;
	if (map[(jump->tl[1] + 1) / PXS -1][(jump->tl[0] + HTX) / PXS] == '1' ||
	map[(jump->bl[1] + 1) / PXS - 1][(jump->tl[0] - HTX) / PXS] == '1')
	{
		distance = jump->tr[1] - (PXS * ((jump->tr[1] + 1) / PXS)) - 1 + 2;
		if (distance > JMPX)
			return (JMPX);
		return (distance);
	}
	if (map[(jump->tl[1]) / PXS][(jump->tl[0] + HTX) / PXS] == '1' ||
	map[(jump->bl[1]) / PXS][(jump->bl[0] - HTX) / PXS] == '1')
		return (-(HTX));
	return (JMPX);
}
