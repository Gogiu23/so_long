/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_central_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:32 by gdominic          #+#    #+#             */
/*   Updated: 2023/02/02 16:47:38 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_generate_actions(int keycode, t_data *data)
{
	ft_call_action(keycode, data);
	return (0);
}

int	ft_clean_hook(int keycode, t_data *data)
{
	if (keycode != 53)
		ft_reset_action(keycode, data);
	else
		ft_exit_game(0, data);
	return (0);
}

int	ft_print_env(t_data *data)
{
//	mlx_clear_window(data->mlx, data->win);
	ft_print_background(data);
	ft_get_player_dimension(data);
//	ft_print_wall(data);
	ft_print_exit(data);
	ft_print_collectable(data);
	ft_print_player(data);
//	usleep(1000);
	return (1);
}

void	ft_after_loading(t_data *data)
{
//	mlx_destroy_image(data->mlx, data->img);
//	mlx_destroy_window(data->mlx, data->win);
	data->mlx = mlx_init();
	ft_get_player_position(data);
	ft_load_images(data);
	ft_printf("data->map_width: %d\n", data->map_width);
	ft_printf("data->map_height: %d\n", data->map_height);
	data->win = mlx_new_window(data->mlx, (data->map_width * PXS), \
			(data->map_height * PXS), "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, (data->map_width * PXS), \
			(data->map_height * PXS));
	ft_print_background_init(data);
	ft_print_wall(data);
	ft_print_exit(data);
	mlx_hook(data->win, 17, 1L << 0, (void *)exit, 0);
	mlx_hook(data->win, 2, 0, ft_generate_actions, data);
	mlx_key_hook(data->win, ft_clean_hook, data);
	mlx_loop_hook(data->mlx, ft_print_env, data);
	mlx_loop(data->mlx);
}
