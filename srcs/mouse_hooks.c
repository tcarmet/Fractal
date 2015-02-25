/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:14:08 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:14:09 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ITER 1

void		select_win(t_fractal *p)
{
	if (p->statut == 1)
		g()->cur = &g()->p;
	else if (p->statut == 2)
		g()->cur = &g()->p2;
}

int			mouse_hook(int x, int y, t_fractal *p)
{
	select_win(p);
	if (p->which_fractal == JULIA && p->stop_mouse == 0)
	{
		p->c_r = y / (double)SIZE_H * 4 - 2;
		p->c_i = x / (double)SIZE_W * 4 - 2;
		p->refresh = 1;
	}
	return (1);
}

static void	mouse2_hook_scroll_up(int x, int y, t_fractal *p)
{
	p->zoom /= ZOOM;
	p->offset.x = p->offset.x / ZOOM - ((SIZE_W - (SIZE_W / ZOOM)) / 2) /
	ZOOM - (x - SIZE_W / 2) * (1 - (1 / ZOOM)) + ZOOM;
	p->offset.y = p->offset.y / ZOOM - ((SIZE_H - (SIZE_H / ZOOM)) / 2) /
	ZOOM - (y - SIZE_H / 2) * (1 - (1 / ZOOM)) + ZOOM;
	inc_vector(&p->max_iter, -(ITER));
	p->refresh = 1;
}

int			mouse2_hook(int button, int x, int y, t_fractal *p)
{
	if (button == LEFT_CLICK)
	{
		p->stop_mouse = (p->stop_mouse == 0) ? 1 : 0;
		p->refresh = 1;
	}
	if (button == SCROLL_UP)
		mouse2_hook_scroll_up(x, y, p);
	else if (button == SCROLL_DOWN)
	{
		p->zoom *= ZOOM;
		p->offset.x = (p->offset.x + ((SIZE_W - (SIZE_W / ZOOM)) / 2) +
		(x - SIZE_W / 2) * (1 - (1 / ZOOM))) * ZOOM;
		p->offset.y = (p->offset.y + ((SIZE_H - (SIZE_H / ZOOM)) / 2) +
		(y - SIZE_H / 2) * (1 - (1 / ZOOM))) * ZOOM;
		inc_vector(&p->max_iter, ITER);
		p->refresh = 1;
	}
	return (1);
}
