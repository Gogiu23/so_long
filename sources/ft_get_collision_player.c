/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_collision_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:32 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/10 23:53:05 by gdominic         ###   ########.fr       */
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
    if (map[(c->bl[1] + HTX + ETX) / PXS][(c->bl[0] - HTX + ETX) / PXS] == '1' || map[c->br[1] / PXS][(c->br[0] - HTX + ETX) / PXS] == '1')
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

int	ft_top_collision(t_data *data)
{
	 int	dist_coll;
	 t_img	*jump;
	
	 jump = data->imgs;
	 if (data->matrix[(jump->tr[1]) / PXS +1][(jump->tr[0] + HTX) / PXS] == '1' ||
	 data->matrix[(jump->br[1]) / PXS +1][(jump->br[0] - HTX) / PXS] == '1')
	 {
	     dist_coll = (PXS * ((jump->br[1]) / PXS + 1)) - jump->tr[1] -1;
	     if (dist_coll > GVX)
	         return (GVX);
	     return (dist_coll);
	 }
	 return (GVX);
}
