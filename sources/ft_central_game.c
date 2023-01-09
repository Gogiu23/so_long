/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_central_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:32 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 14:51:12 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_print_env(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_get_player_dimension(data);
	ft_print_wall(data);
	ft_print_background(data);
	ft_print_exit(data);
	ft_print_collectable(data);
	ft_print_player(data);
	return (1);
}

void	ft_after_loading(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	data->mlx = mlx_init();
	ft_get_player_position(data);
	ft_load_images(data);
	data->win = mlx_new_window(data->mlx, (data->map_width * 50), \
			(data->map_height * 50), "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, (data->map_width * 50), \
			(data->map_height * 50));
	mlx_hook(data->win, 2, 0, ft_exit_game, data);
	mlx_hook(data->win, 17, 1L << 0, (void *)exit, 0);
	mlx_loop_hook(data->mlx, ft_print_env, data);
	mlx_loop(data->mlx);
}

int	ft_exit_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_free_stacks_t(data);
		mlx_destroy_window(data->mlx, data->win);
		exit (EXIT_SUCCESS);
	}
	else
		ft_call_action(keycode, data);
	return (0);
}
