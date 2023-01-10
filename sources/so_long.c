/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/10 01:58:50 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
//	data = malloc(sizeof (t_data));
//	if (!data)
//		exit (EXIT_FAILURE);
	ft_get_size_map(&data, fd, argv);
	data.step = 0;
	ft_fitoar(&data, fd);
	data.c = 0;
	data.c = 0;
//	ft_get_player_position(&data);
//	ft_print_stack(&data);
//	ft_load_images(&data);
//	ft_check_errors(&data);
//	data.mlx = mlx_init();
	ft_start_game(&data);
//	exit (0);
//	mlx_hook(data.win, 2, 0, ft_next_game, &data);
//	mlx_hook(data.win, 17, 0, (void *)exit, 0);
//	mlx_loop_hook(data.mlx, ft_wait_time, &data);
//	mlx_loop(data.mlx);
	return (0);
}
