/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/14 20:11:53 by gdominic         ###   ########.fr       */
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
	ft_init_game(&data);
	ft_get_size_map(&data, fd, argv);
	ft_fitoar(&data, fd);
	ft_check_errors(&data);
	ft_start_game(&data);
	return (0);
}
