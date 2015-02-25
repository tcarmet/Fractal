/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:12:28 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:12:31 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_g_julia(t_fractal *p)
{
	p->which_fractal = JULIA;
	p->ft_pros = ft_pros_julia;
	p->p1.x = -1;
	p->p1.y = -1.2;
	p->p2.x = 1;
	p->p2.y = 1.2;
	p->x = (p->p2.x - p->p1.x) * p->zoom;
	p->y = (p->p2.y - p->p1.y) * p->zoom;
	p->c_r = 1.417022285;
	p->c_i = 0.01;
}

void	init_g_mandelbrot(t_fractal *p)
{
	p->which_fractal = MANDELBROT;
	p->ft_pros = ft_pros_mandelbrot;
	p->p1.x = -2.1;
	p->p2.x = 0.6;
	p->p1.y = -1.2;
	p->p2.y = 1.2;
	p->x = (p->p2.x - p->p1.x) * p->zoom;
	p->y = (p->p2.y - p->p1.y) * p->zoom;
}

void	ft_pros_julia(t_fractal *p, int x, int y)
{
	p->z_r = (x + p->offset.x) / p->zoom + p->p1.x;
	p->z_i = (y + p->offset.y) / p->zoom + p->p1.y;
}

void	ft_pros_mandelbrot(t_fractal *p, int x, int y)
{
	p->z_r = 0;
	p->z_i = 0;
	p->c_r = (x + p->offset.x) / p->zoom + p->p1.x;
	p->c_i = (y + p->offset.y) / p->zoom + p->p1.y;
}
