/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:43:38 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/13 21:33:50 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	initial_mandelbrot(t_data *img)
{
	img->x_pos = 0.0;
	img->y_pos = 0.0;
	img->width = 750;
	img->height = 750;
	img->max_itr = 150;
	img->scale = 4.6 / img->width;
	img->base_color = 0xF4EBD0;
}

void	change_base_color(t_data *img)
{
	img->base_color = 0x11808C * 45;
	draw_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

int	exit_win(t_data *img)
{
	mlx_clear_window(img->mlx, img->window);
	mlx_destroy_window(img->mlx, img->window);
	ft_putstr("Mandelbrot has been closed using ESC or X");
	exit(0);
}

int	man_calculate_itr(t_data *img)
{
	float	real;
	float	imag;
	int		itr;
	float	new_real;

	real = 0.0;
	imag = 0.0;
	itr = 0;
	new_real = 0.0;
	while (real * real + imag * imag <= 4 && itr < img->max_itr)
	{
		new_real = real * real - imag * imag + img->c_real;
		imag = 2.0 * real * imag + img->c_imag;
		real = new_real;
		itr++;
	}
	return (itr);
}

void	draw_mandelbrot(t_data *img)
{
	int	itr;

	mlx_clear_window(img->mlx, img->window);
	img->row = 0;
	while (img->row < img->height)
	{
		img->column = 0;
		while (img->column < img->width)
		{
			img->c_real = img->x_pos + (img->column - img->width / 2.0)
				* img->scale;
			img->c_imag = img->y_pos + (img->row - img->height / 2.0)
				* img->scale;
			itr = man_calculate_itr(img);
			if (itr == img->max_itr)
				my_mlx_pixel_putm(img, img->column, img->row, 0x00000);
			else
				my_mlx_pixel_putm(img, img->column, img->row,
					img->base_color * itr);
			img->column++;
		}
		img->row++;
	}
}
