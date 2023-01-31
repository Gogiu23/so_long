/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:12:02 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/31 18:11:50 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_fitoar(t_data *data, int fd)
{
	int		i;
	int		nbr;

	i = 0;
	data->map = get_next_line(fd);
	data->matrix = (char **)malloc(sizeof(char *) * data->map_height + 1);
	if (!data->matrix)
		exit (EXIT_FAILURE);
	ft_printf("data->map_height: %d\n", data->map_height);
	ft_printf("data->map_width: %d\n", data->map_width);
	ft_printf("data->map: %d\n", ft_strlen(data->map));
	while (data->map)
	{
		nbr = 0;
		data->matrix[i] = (char *)malloc(sizeof(char) * data->map_width + 1);
		if (!data->matrix[i])
			exit (EXIT_FAILURE);
		while (data->map[nbr])
		{
			data->matrix[i][nbr] = data->map[nbr];
			nbr++;
		}
		data->matrix[i][nbr - 1] = '\0';
		free(data->map);
		data->map = get_next_line(fd);
		i++;
	}
	data->matrix[i] = NULL;
	close(fd);
}
