/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:12:49 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:12:52 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_fractal *p)
{
	p->ft_color = ft_change_color;
}

void	init_point(t_fractal *p)
{
	p->zoom = SIZE_H / 2.5;
	p->max_iter = 50;
	p->offset.x = 0;
	p->offset.y = 0;
}

void	init_monitory(int two_win)
{
	g()->hud.win = mlx_new_window(g()->e.mlx, 300, 600, "Monitory Activity");
	XMoveWindow(((t_xvar *)g()->e.mlx)->display,
		((t_win_list *)g()->hud.win)->window, 600, 0);
	if (two_win)
	{
		XMoveWindow(((t_xvar *)g()->e.mlx)->display,
			((t_win_list *)g()->p2.win)->window, 900, 0);
	}
	mlx_key_hook(g()->hud.win, key_hook, &g()->hud);
	mlx_expose_hook(g()->hud.win, expose_hook_m_a, &g()->hud);
}

void	init_mlx(int two_win)
{
	if ((g()->e.mlx = mlx_init()) == NULL)
		ft_error(SYSCALL);
	g()->cur = &g()->p;
	g()->p.stop_mouse = 0;
	g()->p.refresh = 1;
	g()->p.statut = 1;
	g()->p.win = mlx_new_window(g()->e.mlx, SIZE_H, SIZE_W, "fract'ol");
	g()->p.img.img = mlx_new_image (g()->e.mlx, SIZE_H, SIZE_W);
	g()->p.img.data = mlx_get_data_addr(g()->p.img.img, &g()->p.img.bpp,
		&g()->p.img.sizeline, &g()->p.img.endian);
	if (two_win)
	{
		g()->p2.refresh = 1;
		g()->p2.statut = 2;
		g()->p2.win = mlx_new_window(g()->e.mlx, SIZE_H, SIZE_W, "fract'ol2");
		g()->p2.img.img = mlx_new_image (g()->e.mlx, SIZE_H, SIZE_W);
		g()->p2.img.data = mlx_get_data_addr(g()->p2.img.img, &g()->p2.img.bpp,
		&g()->p2.img.sizeline, &g()->p2.img.endian);
	}
	init_monitory(two_win);
}

void	init_all(void)
{
	g()->p2.win = NULL;
	g()->p.which_fractal = 0;
	g()->p2.which_fractal = 0;
	init_color(&g()->p);
	init_color(&g()->p2);
	init_point(&g()->p);
	init_point(&g()->p2);
}
