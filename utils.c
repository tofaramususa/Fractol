/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:34:10 by tmususa           #+#    #+#             */
/*   Updated: 2023/04/19 16:19:15 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] - s2[i] == 0) && i < n - 1)
			i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

float	int_to_float(char *str, float result)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			i++;
			while (ft_isdigit(str[i]))
			{
				result = result * 10 + str[i] - '0';
				i++;
				point++;
			}
		}
		i++;
	}
	while (point-- > 0)
	{
		result /= 10.0;
	}
	return (result);
}

float	f_loat(char *str)
{
	int			i;
	float		result;
	int			sign;	
	int			point;

	i = 0;
	result = 0.0;
	sign = 1;
	point = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result = int_to_float(str, result);
	return (result * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
