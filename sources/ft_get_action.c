/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:52 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 19:35:07 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	ft_return_action(int keycode)
{
	if (keycode == 0 || keycode == 123)
		return (1);
	else if (keycode == 2 || keycode == 124)
		return (2);
	else if (keycode == 13 || keycode == 126)
		return (10);
	else if (keycode == 14 || keycode == 82)
		return (5);
	else if (keycode == 49)
		return (10);
	return (0);
}

void	ft_call_action(int keycode, t_data *data)
{
	t_img	*action;

	action = data->imgs;
	if (ft_return_action(keycode) != 5)
	{
		if (action->acm[0] == 0 || \
				action->acm[0] == ft_return_action(keycode))
			action->acm[0] = ft_return_action(keycode);
		else if (action->acm[1] == 0 || \
				action->acm[1] == ft_return_action(keycode))
			action->acm[1] = ft_return_action(keycode);
	}
	else
		action->acm[2] = ft_return_action(keycode);
	if (action->acm[0] == 1 || action->acm[1] == 1)
		action->direction = 0;
	if (action->acm[0] == 2 || action->acm[1] == 2)
		action->direction = 1;
	ft_printf("action->acm: %d\n", action->acm[0]);
//	exit (0);
}

void	ft_reset_action(int keycode, t_data *data)
{
	t_img	*action;

	action = data->imgs;
	if (action->acm[0] == ft_return_action(keycode))
		action->acm[0] = 0;
	if (action->acm[1] == ft_return_action(keycode))
		action->acm[1] = 0;
	if (action->acm[0] == 0 && action->acm[1] != 0)
	{
		action->acm[0] = action->acm[1];
		action->acm[1] = 0;
	}
	if (action->acm[2] == ft_return_action(keycode))
		action->acm[2] = 0;
}

int	ft_exit_game(int keycode, t_data *data)
{
	if (keycode == 0)
		mlx_destroy_window(data->mlx, data->win);
	exit (EXIT_SUCCESS);
}
