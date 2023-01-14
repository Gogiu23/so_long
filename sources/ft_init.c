/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:44:24 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/14 19:53:21 by gdominic         ###   ########.fr       */
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

