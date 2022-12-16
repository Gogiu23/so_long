/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:49:27 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 04:26:29 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_check_errors(t_data *data)
{
	ft_check_size_map(data);
}

void	ft_check_size_map(t_data *data)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (data->matrix[i])
	{
		t = i + 1;
		while (data->matrix[t])
		{
			if (ft_strlen(data->matrix[i]) == ft_strlen(data->matrix[t]))
				t++;
			else
			{
				ft_putstr_error("Error\nThe map is not the correct size\n");
				exit (0);
			}
		}
		i++;
	}
}

