/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_central_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:05:32 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/26 06:46:26 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_after_loading(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	ft_load_images(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 50), \
			(data->map_height * 50), "7EVEN SWORDS");
	data->img = mlx_new_image(data->mlx, (data->map_width * 50), (data->map_height * 50));
	ft_first_printmap(data);
	mlx_hook(data->win, 2, 0, ft_exit_game, data);
	mlx_hook(data->win, 17, 0, (void *)exit, 0);
	mlx_loop_hook(data->mlx, ft_first_printmap, data);
	mlx_loop(data->mlx);
}

void	ft_load_images(t_data *data)
{
	data->imgs = malloc(sizeof(t_img) * (6));
	if (!data->imgs)
		free(data->imgs);
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx, \
			"images/image-12wallgrey2.xpm", &data->img_width, &data->img_height);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img, \
			&data->imgs[0].bpp, &data->imgs[0].length, &data->imgs[0].endian);
	data->imgs[1].img =  mlx_xpm_file_to_image(data->mlx, \
			"images/playerground3.xpm", &data->img_width, &data->img_height);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img, \
			&data->imgs[1].bpp, &data->imgs[1].length, &data->imgs[1].endian);
	data->imgs[2].img =  mlx_xpm_file_to_image(data->mlx, \
			"images/ground.xpm", &data->img_width, &data->img_height);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img, \
			&data->imgs[2].bpp, &data->imgs[2].length, &data->imgs[2].endian);
	data->imgs[3].img =  mlx_xpm_file_to_image(data->mlx, \
			"images/collectable.xpm", &data->img_width, &data->img_height);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img, \
			&data->imgs[3].bpp, &data->imgs[3].length, &data->imgs[3].endian);
	data->imgs[4].img =  mlx_xpm_file_to_image(data->mlx, \
			"images/Slice-3door-exit.xpm", &data->img_width, &data->img_height);
	data->imgs[4].addr = mlx_get_data_addr(data->imgs[4].img, \
			&data->imgs[4].bpp, &data->imgs[4].length, &data->imgs[4].endian);
	data->imgs[5].img = mlx_xpm_file_to_image(data->mlx, "images/Slice-1playerground.xpm", \
			&data->img_width, &data->img_height);
	data->imgs[5].addr = mlx_get_data_addr(data->imgs[5].img, \
			&data->imgs[5].bpp, &data->imgs[5].length, &data->imgs[5].endian);
}

void 	ft_second_printmap(t_data *data, int a, int b)
{	
	if (data->matrix[a][b] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[2].img, (b * 50), (a * 50));
	else if (data->matrix[a][b] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[3].img, (b * 50), (a * 50));
	if (data->matrix[a][b] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[4].img, (b * 50), (a * 50));
}

void 	ft_player_stop(t_data *data, int a, int b)
{
	if (data->matrix[a][b] == 'P' && data->x == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[5].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 2)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 3)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[5].img, (b * 50), (a * 50));
		data->x++;
	}
	else if (data->matrix[a][b] == 'P' && data->x == 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
				data->imgs[1].img, (b * 50), (a * 50));
		data->x = 0;
	}
	usleep(500);
}

int	ft_first_printmap(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->matrix[a])
	{
		b = 0;
		while (data->matrix[a][b])
		{
			if (data->matrix[a][b] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
						data->imgs[0].img, (b * 50), (a * 50));
//			ft_printf("X: %d\n", data->x);
			ft_player_stop(data, a, b);
			ft_second_printmap(data, a, b);
			b++;
		}
		a++;
	}
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF4550, "Esc = exit game");
	return (0);
}

int	ft_exit_game(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		ft_free_stacks_t(data);
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}
