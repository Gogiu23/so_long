/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_dimension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:13 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 14:32:24 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_player_dimension(t_data *data)
{
	t_img	*zone;

	zone = data->imgs;
	zone->tl[0] = zone->pl[0];
	zone->tl[1] = zone->pl[1];
	zone->tr[0] = zone->tl[0];
	zone->tr[1] = zone->tl[1] + PXS;
	zone->bl[0] = zone->tl[0] + PXS;
	zone->bl[1] = zone->tl[1];
	zone->br[0] = zone->tl[0] + PXS;
	zone->br[1] = zone->tl[1] + PXS;
}
