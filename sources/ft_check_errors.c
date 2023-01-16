/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:49:27 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/16 11:54:55 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_check_errors(t_data *data)
{
	if (ft_check_size_map(data) == 0)
		ft_putstr_error("Invalid map size\n");
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
