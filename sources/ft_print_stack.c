/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 20:55:37 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/15 03:25:20 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_print_stack(t_data *t)
{
	int	i;

	i = 0;
	while (t->matrix[i])
	{
		ft_printf("array t->marrix[%d]: %s\n", i, t->matrix[i]);
		i++;
	}
	ft_printf("Prueba de array: %c\n", t->matrix[2][9]);
}
