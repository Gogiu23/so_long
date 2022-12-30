/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:12:02 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/30 06:27:34 by gdominic         ###   ########.fr       */
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
	data->matrix = (char **)malloc(sizeof(char *) * data->map_height - 1);
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
	ft_get_player_position(data);
}

void	ft_get_player_position(t_data *data)
{
	int	x;
	int	y;
	int	t;

	t = 1;
	x = 0;
	while (data->matrix[x])
	{
//		ft_printf("aqui\n");
		y = 0;
		while (data->matrix[x][y])
		{
//			ft_printf("aqui 2\n");
			if (ft_strncmp(data->matrix[x], "P", data->map_width) == 0)
			{
				data->imgs->plpo[0] = x - 1;
				return ;
			}
			t++;
			y++;
		}
		x++;
	}
	ft_printf("Valor de t: %d\n", t);
	ft_printf("Valor de y: %d\n", y);
	ft_printf("Valor de x: %d\n", x);
	ft_printf("Valor de plpo: %d\n", data->imgs->plpo);
//	data->imgs->plpo[1] = y;
}
