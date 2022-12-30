/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_central_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:32 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/30 05:15:52 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_after_loading(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	ft_load_images(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 50), \
			(data->map_height * 50), "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, (data->map_width * 50), (data->map_height * 50));
	ft_first_printmap(data);
	mlx_hook(data->win, 2, 0, ft_exit_game, data);
	mlx_hook(data->win, 17, 0, (void *)exit, 0);
	mlx_loop_hook(data->mlx, ft_first_printmap, data);
	mlx_loop(data->mlx);
}

int	ft_exit_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_free_stacks_t(data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
//	else if (keycode == 2 || keycode == 124)
//		ft_player_move_right(data);
//	else if (keycode == 0 || keycode == 123)
//		ft_player_move_left(data);
//	else if (keycode == 13 || keycode == 126)
//		ft_player_move_up(data);
//	else if (keycode == 1 || keycode == 125)
//		ft_player_move_down(data);
	return (0);
}
