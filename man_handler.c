/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:11:27 by tmususa           #+#    #+#             */
/*   Updated: 2023/04/19 16:26:38 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	man_keypress(int keycode, t_data *img)
{
	if (keycode == 53)
		exit_win(img);
	else if (keycode >= 123 && keycode <= 126)
		move_man(keycode, img);
	else if (keycode == 8)
		change_base_color(img);
	else if (keycode == 9)
		reset_man(img);
	return (0);
}

int	zoom_scroll(int button, int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->window);
	if (button == 5)
		img->scale *= 1.1;
	else if (button == 4)
		img->scale /= 1.1;
	draw_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	return (0);
	x++;
	y++;
}

void	reset_man(t_data *img)
{
	img->x_pos = 0.0;
	img->y_pos = 0.0;
	img->max_itr = 150;
	img->scale = 4.6 / img->width;
	img->base_color = 0xF4EBD0;
	draw_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

void	move_man(int keycode, t_data *img)
{
	if (keycode == 123)
	{
		img-> x_pos += 0.1;
		draw_mandelbrot(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 124)
	{
		img-> x_pos -= 0.1;
		draw_mandelbrot(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 125)
	{
		img-> y_pos -= 0.1;
		draw_mandelbrot(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 126)
	{
		img-> y_pos += 0.1;
		draw_mandelbrot(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
}

void	mandelbrot(void)
{
	t_data	img;

	initial_mandelbrot(&img);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.height, img.width, "Mandelbrot");
	img.img = mlx_new_image(img.mlx, 750, 750);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_mandelbrot(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_hook(img.window, 02, 1L << 0, man_keypress, &img);
	mlx_hook(img.window, 4, 0, zoom_scroll, &img);
	mlx_hook(img.window, 17, 1L << 0, exit_win, &img);
	mlx_loop(img.mlx);
}
