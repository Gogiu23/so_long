/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:12:02 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/01 11:55:19 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_fitoar(t_data *t, int fd)
{
	char	*map;
	int		i;

	i = 0;
	map = get_next_line(fd);
	t->matrix = (char **)malloc(sizeof(char *));
	if(!t->matrix)
		free(t->matrix);
	while (map)
	{
		t->matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(map) + 1);
		t->matrix[i] = map;
//		free(map);
		map = get_next_line(fd);
		i++;
	}
	t->matrix[i] = NULL;
	map = NULL;
//	free(map);
}
