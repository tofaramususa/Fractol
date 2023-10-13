/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:50:04 by tmususa           #+#    #+#             */
/*   Updated: 2023/04/19 16:28:01 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	initial_julia(t_data *img, float x_real, float y_imag)
{
	img->x_pos = 0.0;
	img->y_pos = 0.0;
	img->width = 750;
	img->height = 750;
	img->max_itr = 150;
	img->scale = 4.6 / img->width;
	img->base_color = 0xB6E2D3;
	img->x_real = x_real;
	img->y_imag = y_imag;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calculate_itr(t_data *img)
{
	float	new_real;
	int		itr;

	itr = 0;
	while (img->z_real * img->z_real + img->z_imag * img->z_imag <= 4
		&& itr < img->max_itr)
	{
		new_real = img->z_real * img->z_real - img->z_imag * img->z_imag;
		img->z_imag = 2.0 * img->z_real * img->z_imag + img->y_imag;
		img->z_real = new_real + img->x_real;
		itr++;
	}
	return (itr);
}

void	draw_julia(t_data *img)
{
	int	itr;

	mlx_clear_window(img->mlx, img->window);
	img->row = 0;
	while (img->row < img->height)
	{
		img->column = 0;
		while (img->column < img->width)
		{
			img->z_real = img->x_pos + (img->column - img->width / 2.0)
				* img->scale;
			img->z_imag = img->y_pos + (img->row - img->height / 2.0)
				* img->scale;
			itr = calculate_itr(img);
			if (itr == img->max_itr)
				my_mlx_pixel_put(img, img->column, img->row, 0x00000);
			else
				my_mlx_pixel_put(img, img->column, img->row,
					img->base_color * itr);
			img->column++;
		}
		img->row++;
	}
}

void	julia(float x_real, float y_imag)
{
	t_data	img;

	initial_julia(&img, x_real, y_imag);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.height, img.width, "Julia");
	img.img = mlx_new_image(img.mlx, 750, 750);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_julia(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_hook(img.window, 02, 1L << 0, jul_keypress, &img);
	mlx_hook(img.window, 4, 0, jul_zoom_scroll, &img);
	mlx_hook(img.window, 17, 1L << 0, jul_exit_win, &img);
	mlx_loop(img.mlx);
}
