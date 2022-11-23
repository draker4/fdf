/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:24:04 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 10:29:12 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_list	*list;
	t_data	img;

	(void) argc;
	list = NULL;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Bperriol the best !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	if (!ft_parse(list, argv[1]))
		return (1);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
