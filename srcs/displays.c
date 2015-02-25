/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:12:19 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:12:22 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*display_fractal_name(t_fractal *p)
{
	if (p->which_fractal == MANDELBROT)
		return ("Mandelbrot");
	if (p->which_fractal == JULIA)
		return ("Julia");
	if (p->which_fractal == CHROMOSOM)
		return ("Chromosom");
	if (p->which_fractal == NOUN)
		return ("Noun");
	return ("");
}

char	*check_mouse(int stop_mouse)
{
	if (stop_mouse == 1)
		return ("off");
	else
		return ("on");
	return (NULL);
}

void	display_ui_textp2(void *win)
{
	char *str;

	str = ft_llitoa(g()->p2.max_iter);
	PUT_W(g()->e.mlx, win, 5, 160, VERT, "Iterations :");
	PUT_W(g()->e.mlx, win, 100, 160, VERT, str);
	PUT_W(g()->e.mlx, win, 5, 170, VERT, "Zoom :");
	free(str);
	str = ft_llitoa(g()->p2.zoom);
	PUT_W(g()->e.mlx, win, 100, 170, VERT, str);
	free(str);
	PUT_W(g()->e.mlx, win, 5, 180, VERT, "MOUSE->");
	PUT_W(g()->e.mlx, win, 100, 180, VERT, check_mouse(g()->p2.stop_mouse));
	PUT_W(g()->e.mlx, win, 5, 190, VERT, "move x:");
	str = ft_llitoa(g()->p2.offset.x);
	PUT_W(g()->e.mlx, win, 100, 190, VERT, str);
	PUT_W(g()->e.mlx, win, 5, 200, VERT, "move y:");
	free(str);
	str = ft_llitoa(g()->p2.offset.y);
	PUT_W(g()->e.mlx, win, 100, 200, VERT, str);
	free(str);
}

void	display_ui_text(void *win)
{
	char *str;

	str = ft_llitoa(g()->p.max_iter);
	mlx_clear_window(g()->e.mlx, win);
	PUT_W(g()->e.mlx, win, 5, 20, WHITE, "Arrows keys to move.");
	PUT_W(g()->e.mlx, win, 5, 40, WHITE, "Left click to stop mouse capture.");
	PUT_W(g()->e.mlx, win, 5, 60, WHITE, "* to inc. iteration, / to dec.");
	PUT_W(g()->e.mlx, win, 5, 80, WHITE, "Spacebar to reset view");
	PUT_W(g()->e.mlx, win, 5, 100, UI_COLOR, "Iterations :");
	PUT_W(g()->e.mlx, win, 100, 100, UI_COLOR, str);
	PUT_W(g()->e.mlx, win, 5, 110, UI_COLOR, "Zoom :");
	PUT_W(g()->e.mlx, win, 5, 120, UI_COLOR, "MOUSE->");
	PUT_W(g()->e.mlx, win, 100, 120, UI_COLOR, check_mouse(g()->p.stop_mouse));
	PUT_W(g()->e.mlx, win, 5, 130, UI_COLOR, "move x:");
	str = ft_llitoa(g()->p.offset.x);
	PUT_W(g()->e.mlx, win, 100, 130, UI_COLOR, str);
	free(str);
	PUT_W(g()->e.mlx, win, 5, 140, UI_COLOR, "move y:");
	str = ft_llitoa(g()->p.offset.y);
	PUT_W(g()->e.mlx, win, 100, 140, UI_COLOR, str);
	free(str);
	str = ft_llitoa(g()->p.zoom);
	PUT_W(g()->e.mlx, win, 100, 110, UI_COLOR, str);
	free(str);
	(g()->p2.win != NULL) ? display_ui_textp2(win) : ' ';
}
