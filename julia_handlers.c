/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:09:46 by tmususa           #+#    #+#             */
/*   Updated: 2023/04/19 15:07:55 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	jul_keypress(int keycode, t_data *img)
{
	if (keycode == 53)
		exit_win(img);
	else if (keycode >= 123 && keycode <= 126)
		change_c_jul(keycode, img);
	else if (keycode == 8)
		jul_change_base_color(img);
	return (0);
}

int	jul_zoom_scroll(int button, int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->window);
	if (button == 5)
		img->scale *= 1.1;
	else if (button == 4)
		img->scale /= 1.1;
	draw_julia(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	x++;
	y++;
	return (0);
}

void	change_c_jul(int keycode, t_data *img)
{
	if (keycode == 123)
	{
		img-> x_real -= 0.1;
		draw_julia(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 124)
	{
		img-> x_real += 0.1;
		draw_julia(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 125)
	{
		img-> y_imag -= 0.1;
		draw_julia(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 126)
	{
		img-> y_imag += 0.1;
		draw_julia(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
}

void	jul_change_base_color(t_data *img)
{
	img->base_color = 0x11808C * 45;
	draw_julia(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

int	jul_exit_win(t_data *img)
{
	mlx_clear_window(img->mlx, img->window);
	mlx_destroy_window(img->mlx, img->window);
	ft_putstr("Julia has been closed using ESC or X");
	exit(0);
}
