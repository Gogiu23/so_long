/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/28 20:01:27 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_data 	data;
	int		fd;
//	int		i;
	char	*map;

//	i = 0;
	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map = get_next_line(fd);
	while (map)
	{
		ft_printf("%s\n", map);
		map = get_next_line(fd);
//		i++;
	}
//	ft_printf("%d\n", map);
//	ft_printf("%s\n", map);
	data.x = 5;
	data.y = 5;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1240, 720, "Hello world");
	data.img = mlx_new_image(data.mlx, 1240, 720);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	if (ft_strncmp(argv[1], "square", 8) == 0)
		ft_square(&data);
	if (ft_strncmp(argv[1], "triangle", 8) == 0)
		ft_triangle(&data);
	close(fd);
	return (0);
}

//typedef struct	s_vars {
//	void	*mlx;
//	void	*win;
//	int		size_x;
//	int		size_y;
//}t_vars;
//
//int	close2(int keycode, t_vars *vars)
//{
////	if (keycode == 53)
//	vars = 0;
//	if (keycode == 53)
//		ft_printf("Hola\n");
//	return (0);
//}
//
//int	main(void)
//{
//	t_vars	vars;
//
//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
//	mlx_hook(vars.win, 12, 0, close2, &vars);
//	mlx_loop(vars.mlx);
//}
