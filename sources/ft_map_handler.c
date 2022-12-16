/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:45:35 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 18:50:34 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_get_size_map(t_data *data, int fd, char **argv)
{
	int	i;

	i = 0;
	data->map_size = 0;
//	data->map = (char *)malloc(sizeof (char));
//	data->map = get_next_line(fd);
	while (1)
	{
//		printf("Here\n");
		data->map = get_next_line(fd);
		if (!data->map)
			break;
		free(data->map);
		data->map_size++;
//		ft_printf("Valore de data->map: \n%s\n", data->map);
//		ft_printf("valor de map_size: %d\n", data->map_size);
	}
//	data->map_size = read(fd, buffer, 1000);
//	while (buffer != NULL)
//	{
//		if (ft_strchr(buffer, '\n') != 0)
//			i++;
//		count++;
//	}
//	ft_printf("valor de count: %d\n", count);
//	free(buffer);
//	free(data->map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
}
//void	ft_get_map(t_data *data, int fd)
//{
//	data->map_size = 0;
//
//	data->map = get_next_line(fd);
//	while (data->map)
//	{
//		data->map_size += ft_strlen(data->map) + 1;
//		ft_printf("Valor de data->map_size: %d\n", data->map_size);
////		ft_fitoar(data);
//		free(data->map);
//		data->map = get_next_line(fd);
//	}
//	close(fd);
//}
