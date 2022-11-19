/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/19 06:10:25 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void 	*mlx_win;
	t_data 	img;
	int		x = 5;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1240, 720, "Hello world");
	img.img = mlx_new_image(mlx, 1240, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 100)
	{
		my_mlx_pixel_put(&img, x, 5, 0x00FF0001);
		x++;
	}
	while (x < 100)
	{
		mlx_put_image_to_window(mlx, mlx_win, img.img, x, 0);
		x++;
	}
	mlx_loop(mlx);
}
