/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:58:33 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/04 16:31:28 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

void	ft_load_images(t_data *data)
{
	data->imgs = malloc(sizeof(t_img) * (10));
	if (!data->imgs)
		free(data->imgs);
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx, \
			"images/image-12wallgrey2.xpm", &data->img_width, \
			&data->img_height);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img, \
			&data->imgs[0].bpp, &data->imgs[0].length, &data->imgs[0].endian);
	data->imgs[1].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player1.png", &data->img_width, \
			&data->img_height);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img, \
			&data->imgs[1].bpp, &data->imgs[1].length, &data->imgs[1].endian);
	data->imgs[2].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player2.png", \
			&data->img_width, &data->img_height);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img, \
			&data->imgs[2].bpp, &data->imgs[2].length, &data->imgs[2].endian);
	data->imgs[3].img = mlx_xpm_file_to_image(data->mlx, \
			"images/ground.xpm", &data->img_width, &data->img_height);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img, \
			&data->imgs[3].bpp, &data->imgs[3].length, &data->imgs[3].endian);
	ft_load_more_images(data);
}

void	ft_load_more_images(t_data *data)
{
	data->imgs[4].img = mlx_xpm_file_to_image(data->mlx, \
			"images/collectable.xpm", &data->img_width, &data->img_height);
	data->imgs[4].addr = mlx_get_data_addr(data->imgs[4].img, \
			&data->imgs[4].bpp, &data->imgs[4].length, &data->imgs[4].endian);
	data->imgs[5].img = mlx_xpm_file_to_image(data->mlx, \
			"images/Slice-3door-exit.xpm", &data->img_width, &data->img_height);
	data->imgs[5].addr = mlx_get_data_addr(data->imgs[5].img, \
			&data->imgs[5].bpp, &data->imgs[5].length, &data->imgs[5].endian);
	data->imgs[6].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player3.png", &data->img_width, &data->img_height);
	data->imgs[6].addr = mlx_get_data_addr(data->imgs[6].img, \
			&data->imgs[6].bpp, &data->imgs[6].length, &data->imgs[6].endian);
	data->imgs[7].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player4.png", &data->img_width, &data->img_height);
	data->imgs[7].addr = mlx_get_data_addr(data->imgs[7].img, \
			&data->imgs[7].bpp, &data->imgs[7].length, &data->imgs[7].endian);
	data->imgs[8].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player5.png", &data->img_width, &data->img_height);
	data->imgs[8].addr = mlx_get_data_addr(data->imgs[8].img, \
			&data->imgs[8].bpp, &data->imgs[8].length, &data->imgs[8].endian);
	data->imgs[9].img = mlx_png_file_to_image(data->mlx, \
			"images/plstop_noback/player6.png", &data->img_width, &data->img_height);
	data->imgs[9].addr = mlx_get_data_addr(data->imgs[9].img, \
			&data->imgs[9].bpp, &data->imgs[9].length, &data->imgs[9].endian);
}
