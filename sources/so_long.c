/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/13 04:51:26 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

//int	main(int argc, char **argv)
int	main()
{
	t_data	data;
	data.mlx = mlx_init();
//	t_data	t;
//	int		fd;

//	if (argc == 1)
//		return (0);
//	fd = open(argv[1], O_RDONLY);
//	ft_fitoar(&t, fd);
//	ft_print_stack(&t);
	ft_start_game(&data);
//	close(fd);
//	ft_free_stacks_t(&t);
	mlx_loop(data.mlx);
	return (0);
}
