/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:43:39 by tmususa           #+#    #+#             */
/*   Updated: 2023/04/19 15:52:28 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*data;
	char	*addr;
	void	*mlx;
	void	*window;	
	int		endian;
	int		width;
	int		bits_per_pixel;
	int		height;
	int		max_itr;
	int		line_length;
	int		base_color;
	int		row;
	int		column;
	float	scale;
	float	z_real;
	float	z_imag;
	float	x_pos;
	float	y_pos;
	float	x_real;
	float	y_imag;
	float	c_real;
	float	c_imag;
}	t_data;

int		options(void);
void	mandelbrot(void);
int		ft_isdigit(int c);
float	f_loat(char *str);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		exit_win(t_data *img);
void	reset_man(t_data *img);
void	draw_julia(t_data *img);
int		jul_exit_win(t_data *img);
int		calculate_itr(t_data *img);
void	draw_mandelbrot(t_data *img);
void	change_base_color(t_data *img);
void	change_base_color(t_data *img);
int		man_calculate_itr(t_data *img);
void	initial_mandelbrot(t_data *img);
void	julia(float x_real, float y_imag);
void	move_man(int keycode, t_data *img);
void	jul_change_base_color(t_data *img);
int		man_keypress(int keycode, t_data *img);
void	change_c_jul(int keycode, t_data *img);
int		jul_keypress(int keycode, t_data *img);
int		ft_strncmp(const char *s1, const char *s2, int n);
float	int_to_float(char *str, float result);
int		zoom_scroll(int button, int x, int y, t_data *img);
void	initial_julia(t_data *img, float x_real, float y_imag);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_putm(t_data *data, int x, int y, int color);
int		jul_zoom_scroll(int button, int x, int y, t_data *img);

#endif