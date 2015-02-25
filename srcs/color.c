/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:12:08 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:12:09 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_change_color(int i)
{
	if (i % 3 == 0)
		return (BLEU);
	else if (i % 5 == 0)
		return (WHITE);
	else if (i % 7 == 0)
		return (ROUGE);
	else
		return (NIGGA);
}

int	ft_change_color2(int i)
{
	if (i % 3 == 0)
		return (VERT);
	else if (i % 5 == 0)
		return (JAUNE);
	else if (i % 7 == 0)
		return (BLEU);
	else
		return (NIGGA);
}

int	ft_change_color3(int i)
{
	if (i % 3 == 0)
		return (VERT);
	else if (i % 5 == 0)
		return (WHITE);
	else if (i % 7 == 0)
		return (ROUGE);
	else if (i % 11 == 0)
		return (TURQUOISE);
	else
		return (VIOLET);
}

int	ft_change_color4(int i)
{
	if (i % 3 == 0)
		return (ORANGE);
	else if (i % 5 == 0)
		return (PEACEFUL);
	else if (i % 7 == 0)
		return (BALANCE);
	else
		return (NIGGA);
}

int	ft_change_color5(int i)
{
	if (i % 2 == 0)
		return (0xfcfdff);
	else if (i % 3 == 0)
		return (0xe0e1e4);
	else if (i % 5 == 0)
		return (0xc4c4c7);
	else if (i % 7 == 0)
		return (0xa0a1a2);
	else if (i % 11 == 0)
		return (0x868688);
	else if (i % 13 == 0)
		return (0x5f6061);
	else if (i % 17 == 0)
		return (0x424343);
	else if (i % 23 == 0)
		return (0x2d2d2d);
	else if (i % 29 == 0)
		return (0x1c1c1c);
	else if (i % 31 == 0)
		return (0x0e0e0e);
	else if (i % 37 == 0)
		return (0x000000);
	else
		return (NIGGA);
}
