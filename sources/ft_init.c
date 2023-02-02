/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:44:24 by gdominic          #+#    #+#             */
/*   Updated: 2023/02/02 18:15:39 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

void	ft_init_game(t_data *data)
{
	t_img	*init;

	data->imgs = ft_calloc((sizeof (t_img) * 1), 1);
	if (!data->imgs)
		exit (EXIT_FAILURE);
	init = data->imgs;
	init->nc = 0;
	init->np = 0;
	init->ne = 0;
	init->sp = 0;
	init->direction = 0;
	init->velocity = 0;
	init->deceleration = 0;
	data->time = 0;
	data->step = 0;
	data->c = 0;
	data->x = 0;
	data->y = 0;
}

void	ft_count_chars(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == 'C')
				data->imgs->nc++;
			if (data->matrix[a][b] == 'E')
				data->imgs->ne++;
			if (data->matrix[a][b] == 'P')
				data->imgs->np++;
			b++;
		}
		a++;
	}
}
