/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_central_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:32 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/17 13:27:10 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_after_loading(t_data *data)
{
//	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
//	ft_load_images(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 50), (data->map_height * 50), "Time machine 2");
//	data->img = mlx_new_image(data->mlx, 100, 100);
	mlx_hook(data->win, 2, 0, ft_next_game, data);
	mlx_loop(data->mlx);
}

//void	ft_load_images(t_data *data)
//{
//}


