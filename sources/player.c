/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:05:27 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 19:44:09 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	*ft_get_pl(t_data *data)
{
	static	int	nr;

	if (data->imgs->acm[0] == 2)
	{
		if (nr < 15 && nr > 5)
			nr++;
		else
			nr = 6;
		return (data->pl_img[nr]);
	}
	else
		if (nr < 5)
			nr++;
		else
			nr = 0;
	return (data->pl_img[nr]);
}

static	void	ft_search_player(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == 'P')
				ft_put_img(data, ft_get_pl(data), data->imgs->pl[1], \
						data->imgs->pl[0]);
			b++;
		}
		a++;
	}
}

void	ft_print_player(t_data *data)
{
	ft_player_move_horitzontal(data);
	ft_player_jump(data);
	ft_search_player(data);
}
