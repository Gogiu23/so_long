/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:12:02 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/03 12:39:43 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_fitoar(t_data *t, int fd)
{
	char	*map;
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	map = get_next_line(fd);
	t->matrix = (char **)malloc(sizeof(char *));
	if (!t->matrix)
		exit (0);
	while (map)
	{
		nbr = 0;
		t->matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(map) + 1);
		while (map[nbr])
		{
			t->matrix[i][nbr] = map[nbr];
			nbr++;
		}
		t->matrix[i][nbr + 1] = '\0';
		free(map);
		map = get_next_line(fd);
		i++;
	}
	t->matrix[i] = NULL;
}
