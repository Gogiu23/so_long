/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/16 11:57:24 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win; //call a windows variable
//	
//	mlx = mlx_init(); //return a pointer to mlx variable and initialize correctly the graphical system
//	mlx_win = mlx_new_window(mlx, 1240, 720, "Hello world");
//	mlx_loop(mlx);
//	return (0);
//}

//int	main(void)
//{
//	void	*img;
//	void	*mlx;
//
//	mlx = mlx_init();
//	img = mlx_new_image(mlx, 1240, 720);
//}

//typedef struct	s_data {
//	
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}	t_data;
//
//int	main(void)
//{
//	void	*mlx;
//	t_data	img;
//
//	mlx = mlx_init();
//	img.img = mlx_new_image(mlx, 1240, 720);
//
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//}
typedef struct	s_data {
	
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	main(void)
{
	void	*mlx;
	void 	*mlx_win;
	t_data 	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1240, 720, "Hello world");
	img.img = mlx_new_image(mlx, 1240, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
