/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upload_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:58:33 by gdominic          #+#    #+#             */
/*   Updated: 2023/01/06 19:17:06 by gdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"

static	char	*ft_path_to_sprite(char *img_name, int n)
{
	char	*nmbr;
	char	*str1;
	char	*str2;

	ft_printf("aqui3\n");
	nmbr = ft_itoa(n);
	str1 = ft_strjoin("images/", img_name);
	str2 = ft_strjoin(str1, "/");
//	free(str1);
	str1 = ft_strjoin(str2, img_name);
//	free(str2);
 	str2 = ft_strjoin(str1, nmbr);
//	str1 = ft_strjoin(str2, nmbr);
//	free(str2);
	str1 = ft_strjoin(str2, ".png");
	ft_printf("n: %d\n", n);
	ft_printf("nmbr: %s\n", nmbr);
	ft_printf("str2: %s\n", str1);
//	exit (0);
//	free(str1);
//	free(nmbr);
	return (str1);
}

static	void	ft_final_sprite_loading(int a, char *path, int ty_sprite, \
		t_data *data)
{
	int	size;

	size = PXS;
	ft_printf("a: %d\n", a);
	if (ty_sprite == 1)
		data->cll_img[a - 1] = mlx_png_file_to_image(data->mlx, path, &size, \
				&size);
//	exit (0);
	else if (ty_sprite == 2)
		data->pl_img[a - 1] = mlx_png_file_to_image(data->mlx, path, &size, \
				&size);
	else if (ty_sprite == 3)
		data->gr_img[a - 1] = mlx_png_file_to_image(data->mlx, path, &size, \
				&size);
	else if (ty_sprite == 4)
		data->wll_img[a - 1] = mlx_png_file_to_image(data->mlx, path, &size, \
				&size);
	else if (ty_sprite == 5)
		data->ext_img[a - 1] = mlx_png_file_to_image(data->mlx, path, &size, \
				&size);
}
	
static	void	ft_load_sprites(char *img_name, int mem_sprite, int ty_sprite, \
		t_data *data)
{
	int		i;
	char	*path;
	int		fd;

	i = 0;
	ft_printf("aqui2\n");
	while (i++ < mem_sprite)
	{
		path = ft_path_to_sprite(img_name, i - 1);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			ft_putstr_error("Error Image not found\n");
		close (fd);
		ft_final_sprite_loading(i, path, ty_sprite, data);
		free(path);
	}
}

void	ft_load_images(t_data *data)
{
	ft_printf("aqui1\n");
	ft_load_sprites("cll", 5, 1, data);
	ft_load_sprites("player", 16, 2, data);
	ft_load_sprites("ground", 1, 3, data);
	ft_load_sprites("wallgrey", 1, 4, data);
	ft_load_sprites("exit", 2, 5, data);
}
