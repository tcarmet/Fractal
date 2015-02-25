/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:12:40 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:12:41 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_fractal *p)
{
	p->refresh = 1;
	return (1);
}

int			expose_hook_m_a(void)
{
	display_ui_text(g()->hud.win);
	return (1);
}

int			loop_hook(t_fractal **p)
{
	if ((*p)->refresh)
	{
		ft_bzero((*p)->img.data, SIZE_H * SIZE_W * 4);
		update_brot(*p);
		mlx_put_image_to_window(g()->e.mlx, (*p)->win, (*p)->img.img, 0, 0);
		display_ui_text(g()->hud.win);
		(*p)->refresh = 0;
	}
	return (1);
}

static void	alpha_num_operateur(int keycode, t_fractal *p)
{
	if (keycode == K_MULT)
		inc_vector(&p->max_iter, 5);
	if (keycode == K_DIV)
		inc_vector(&p->max_iter, -5);
	if (keycode == ALPHA_NUM_1)
		p->ft_color = ft_change_color;
	if (keycode == ALPHA_NUM_2)
		p->ft_color = ft_change_color2;
	if (keycode == ALPHA_NUM_3)
		p->ft_color = ft_change_color3;
	if (keycode == ALPHA_NUM_4)
		p->ft_color = ft_change_color4;
	if (keycode == ALPHA_NUM_5)
		p->ft_color = ft_change_color5;
}

int			key_hook(int keycode, t_fractal *p)
{
	if (keycode)
	{
		if (keycode == ECHAP)
			exit_free();
		if (keycode == SPACE)
			init_point(p);
		if (keycode == DOWN)
			p->offset.y += 10;
		if (keycode == UP)
			p->offset.y -= 10;
		if (keycode == LEFT)
			p->offset.x += 10;
		if (keycode == RIGHT)
			p->offset.x -= 10;
		if (keycode == PLUS)
			p->zoom += 10;
		if (keycode == MOIN)
			p->zoom -= 10;
		alpha_num_operateur(keycode, p);
		p->refresh = 1;
	}
	return (1);
}
