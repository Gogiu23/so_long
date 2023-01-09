/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:32:52 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/09 15:21:25 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_return_action(int keycode)
{
	if (keycode == 2 || keycode == 124)
		return (1);
	else if (keycode == 0 || keycode == 123)
		return (2);
	else if (keycode == 13 || keycode == 126)
		return (10);
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
				action->acm[0] == ft_return_action(keycode))
			action->acm[1] = ft_return_action(keycode);
	}
	else
		action->acm[2] = ft_return_action(keycode);
	if (action->acm[0] == 1 || action->acm[1] == 1)
		action->direction = 1;
	if (action->acm[0] == 2 || action->acm[1] == 2)
		action->direction = 0;
}
