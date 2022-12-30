/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:45:35 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/30 05:35:04 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_get_size_map(t_data *data, int fd, char **argv)
{
	data->map_height = 0;
	while (1)
	{
		data->map = get_next_line(fd);
		if (!data->map)
			break;
		data->map_width = ft_strlen(data->map) - 1;
		free(data->map);
		data->map_height++;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
}
