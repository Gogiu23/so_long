/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 02:21:33 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/16 04:28:08 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_free_stacks_t(t_data *t)
{
	int	nbr;

	nbr = 0;
	if (t->matrix)
	{
		while (t->matrix[nbr])
		{
			free(t->matrix[nbr]);
			nbr++;
		}
		free(t->matrix);
	}
}
