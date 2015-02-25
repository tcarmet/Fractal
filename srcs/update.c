/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:14:19 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:14:19 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_brot_put_img(t_fractal *cur, int x, int y, int i)
{
	if (i == cur->max_iter)
		ft_put_img_pix(&cur->img, x, y, 0x000000);
	else
		ft_put_img_pix(&cur->img, x, y, cur->ft_color(i));
}

void	update_brot(t_fractal *cur)
{
	int		pos[3];
	double	tmp;

	pos[0] = 0;
	while (pos[0] < SIZE_W)
	{
		pos[1] = 0;
		while (pos[1] < SIZE_H)
		{
			pos[2] = 0;
			cur->ft_pros(cur, pos[0], pos[1]);
			while ((pos[2] < cur->max_iter) &&
				(cur->z_r * cur->z_r + cur->z_i * cur->z_i < 4))
			{
				tmp = cur->z_r;
				cur->z_r = cur->z_r * cur->z_r - cur->z_i * cur->z_i + cur->c_r;
				cur->z_i = 2 * cur->z_i * tmp + cur->c_i;
				++pos[2];
			}
			update_brot_put_img(cur, pos[0], pos[1], pos[2]);
			++pos[1];
		}
		++pos[0];
	}
}

void	first_display_secwin(int *i)
{
	t_fractal *tmp;

	tmp = &g()->p2;
	loop_hook(&tmp);
	*i += 1;
}

void	handle_second_win(void)
{
	static int i = 0;

	mlx_hook(g()->p2.win, 6, 64, &mouse_hook, &g()->p2);
	mlx_key_hook(g()->p2.win, key_hook, &g()->p2);
	mlx_mouse_hook(g()->p2.win, mouse2_hook, &g()->p2);
	mlx_expose_hook(g()->p2.win, expose_hook, &g()->p2);
	if (i == 0)
		first_display_secwin(&i);
}
