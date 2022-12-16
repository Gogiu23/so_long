/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:12:02 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 19:13:17 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_fitoar(t_data *data, int fd)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	data->map = get_next_line(fd);
	data->matrix = (char **)malloc(sizeof(char *) * data->map_size - 1);
	ft_printf("mapa size: %d\n", data->map_size);
	if (!data->matrix)
		exit (0);
	while (data->map)
	{
		nbr = 0;
		data->matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(data->map));
		while (data->map[nbr])
		{
			data->matrix[i][nbr] = data->map[nbr];
			nbr++;
		}
		data->matrix[i][nbr] = '\0';
		free(data->map);
		data->map = get_next_line(fd);
		i++;
	}
	data->matrix[i] = NULL;
	close(fd);
}
