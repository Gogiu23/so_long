/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 04:27:22 by gdominic         ###   ########.fr       */
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
	ft_get_size_map(&data, fd, argv);
	ft_fitoar(&data, fd);
	ft_print_stack(&data);
	ft_check_errors(&data);
	data.mlx = mlx_init();
	ft_start_game(&data);
	mlx_hook(data.win, 2, 0, ft_next_game, &data);
	mlx_loop(data.mlx);
	close(fd);
	ft_free_stacks_t(&data);
	return (0);
}
