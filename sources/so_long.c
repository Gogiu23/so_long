/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/12/08 20:58:43 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_data	t;
	int		fd;
// 	char	*relative_path = "../images/image-1.xpm";
	int		img_width;
	int		img_height;

	img_width = 500;
	img_height = 500;
	if (argc == 1)
		return (0);
//	argv = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_fitoar(&t, fd);
	ft_print_stack(&t);
	data.x = 150;
	data.y = 150;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1240, 720, "Hello world");
	data.img = mlx_new_image(data.mlx, 1240, 720);
	data.pic = mlx_xpm_file_to_image(data.mlx, "images/image-1.xpm", &img_width, &img_height);
//	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
//			&data.line_length, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.pic, data.x, data.y);
	mlx_loop(data.mlx);
//	if (ft_strncmp(argv[1], "square", 8) == 0)
//		ft_square(&data);
//	if (ft_strncmp(argv[1], "triangle", 8) == 0)
//		ft_triangle(&data);
	close(fd);
	ft_free_stacks_t(&t);
	return (0);
}
