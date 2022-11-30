/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:14 by gdominic          #+#    #+#             */
/*   Updated: 2022/11/30 20:12:57 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
//	t_data 	data;
	t_data	text;
	int		fd;
	char	*map;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
//	ft_printf("tamaño de argv: %d\n", ft_strlen(argv[1]));
	map = get_next_line(fd);
	text.matrix = (char **)malloc(sizeof(char *));
	if (!text.matrix)
		return (0);
	while (map)
	{
		text.matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(map) + 1); 
		ft_printf("%s\n", map);
		ft_printf("tamaño de el get next line: %d\n", sizeof(get_next_line(fd)));
		ft_printf("Tamaño de la linia de char: %d\n", ft_strlen(map));
		text.matrix[i] = map;
		map = get_next_line(fd);
		i++;
	}
	text.matrix[i] = NULL;
	i = 0;
	while (text.matrix[i])
	{
		ft_printf("en el array t.matrix en la primera posicion: %s\n", text.matrix[i]);
		i++;
	}
	ft_printf("Prueba de arrays: %c\n", text.matrix[2][9]);
//	ft_printf("tamaño de argv: %d\n", sizeof(argv[1]));
//	data.x = 5;
//	data.y = 5;
//	data.mlx = mlx_init();
//	data.win = mlx_new_window(data.mlx, 1240, 720, "Hello world");
//	data.img = mlx_new_image(data.mlx, 1240, 720);
//	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
//	if (ft_strncmp(argv[1], "square", 8) == 0)
//		ft_square(&data);
//	if (ft_strncmp(argv[1], "triangle", 8) == 0)
//		ft_triangle(&data);
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
