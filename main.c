/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:33:08 by tmususa           #+#    #+#             */
/*   Updated: 2023/10/13 21:24:26 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar(*s);
			s++;
		}
	}
}

void	my_mlx_pixel_putm(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	options(void)
{
	ft_putstr("THESE ARE THE AVAILABLE FRACTALS\n");
	ft_putstr("1.mandelbrot(does not take any parameters)\n");
	ft_putstr("2.julia\n");
	return (0);
}

int	main(int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
	{
		mandelbrot();
		return (0);
	}
	if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		if (ac == 4)
		{
			if (((f_loat(av[2]) <= 2.0 && f_loat(av[2]) >= -2.0))
				&& (f_loat(av[3]) <= 2.0 && f_loat(av[3]) >= -2.0))
				julia(f_loat(av[2]), f_loat(av[3]));
			else
				ft_putstr("Julia parameters have to be between -2 and 2\n");
		}
		else
			ft_putstr("Julia takes TWO parameters");
		return (0);
	}
	options();
	return (0);
}
