/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:13:53 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:13:53 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_global	*g(void)
{
	static t_global *sg = NULL;

	if (!sg)
		sg = malloc(sizeof(t_global));
	return (sg);
}

int			parse_params(char **av)
{
	int			i;
	int			win;
	t_fractal	*p;

	i = 1;
	win = 0;
	p = &g()->p;
	while (av[i])
	{
		if (win == 2)
			ft_error(ONLY_TWO_WIN);
		if (choose_fractol(p, av[i]) == 1)
		{
			p = &g()->p2;
			win++;
		}
		i++;
	}
	return (win - 1);
}

int			choose_fractol(t_fractal *p, char *str)
{
	ft_strlower(str);
	if (ft_strequ(str, "julia"))
		init_g_julia(p);
	else if (ft_strequ(str, "mandelbrot"))
		init_g_mandelbrot(p);
	else if (ft_strequ(str, "chromosom"))
		init_g_chromosom(p);
	else if (ft_strequ(str, "rabbit"))
		init_g_noun(p);
	else
		ft_error(INVALID_ARGZ);
	return (1);
}

int			main(int ac, char **av)
{
	int two_win;

	if (ac < 2)
		ft_error(INVALID_ARGZ);
	init_all();
	two_win = parse_params(av);
	init_mlx(two_win);
	mlx_hook(g()->p.win, 6, 64, &mouse_hook, &g()->p);
	mlx_key_hook(g()->p.win, key_hook, &g()->p);
	mlx_mouse_hook(g()->p.win, mouse2_hook, &g()->p);
	mlx_expose_hook(g()->p.win, expose_hook, &g()->p);
	if (two_win)
		handle_second_win();
	mlx_loop_hook(g()->e.mlx, loop_hook, &g()->cur);
	mlx_loop(g()->e.mlx);
	return (0);
}
