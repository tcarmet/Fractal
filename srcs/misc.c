/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:14:00 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:14:01 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_free(void)
{
	free(g());
	exit(1);
}

void	ft_error(int er)
{
	ft_putstr("Error : ");
	if (er == INVALID_ARGZ)
	{
		ft_putstr("bad utilisation: usage:");
		ft_putendl(" ./fractol <fractol> <second_fractol>");
		ft_putstr("\t\t- Available fractols : MANDELBROT,");
		ft_putendl(" JULIA, RABBIT, or CHROMOSOM");
	}
	if (er == ONLY_TWO_WIN)
		ft_putendl("only two windows are allowed");
	if (er == SYSCALL)
		ft_putendl("syscall failed");
	exit(-1);
}

char	*ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		else
			str[i] = str[i];
		i++;
	}
	return (str);
}

void	inc_vector(double *point, double vector)
{
	if (*point + vector < 2)
		return ;
	*point += vector;
}

void	ft_put_img_pix(t_fimg *img, int x, int y, int color)
{
	unsigned long pos;

	if (x < SIZE_H && y < SIZE_W && x >= 0 && y >= 0)
	{
		pos = y * SIZE_H * 4 + x * 4;
		img->data[pos] = COL_R(color);
		img->data[pos + 1] = COL_G(color);
		img->data[pos + 2] = COL_B(color);
	}
}
