/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:49:27 by gdominic          #+#    #+#             */
/*   Updated: 2023/02/02 18:15:58 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_check_errors(t_data *data)
{
	if (ft_check_size_map(data) == 0)
		ft_putstr_error("Invalid map size\n");
	if (ft_check_char(data) == 0)
		ft_putstr_error("Error: Invalid numbers of chars\n");
}

int	ft_check_size_map(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (data->matrix[a])
	{
		ft_printf("data->matrix[%d]: %s\n", a, data->matrix[a]);
		a++;
	}
	return (1);
}

int	ft_check_char(t_data *data)
{
	t_img	*chars;

	ft_count_chars(data);
	chars = data->imgs;
	if (chars->np > 1)
		return (0);
	else if (chars->ne > 1)
		return (0);
	return (1);	
}
