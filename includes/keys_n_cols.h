/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_n_cols.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:20:01 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:20:02 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_N_COLS_H
# define KEYS_N_COLS_H

# define ROUGE 0xf05032
# define VERT 0x54b847
# define JAUNE 0xfee01e
# define BLACK 0x292e2e
# define BLEU 0x0099ff
# define VIOLET 0x692c90
# define TURQUOISE 0x00e5ee
# define BROWN 0xa52a2a
# define WHITE 0xffffff
# define NIGGA 0x000000
# define ORANGE 0xf97130
# define PEACEFUL 0x76ba26
# define BALANCE 0xc3c3c6
# define COL_B(i) (i >> 16) & 0x000000ff
# define COL_G(i) (i >> 8 ) & 0x000000ff
# define COL_R(i) i & 0x000000ff

typedef enum	e_error
{
	INVALID_ARGZ,
	ONLY_TWO_WIN,
	SYSCALL,
}				t_error;

typedef enum	e_fractol
{
	MANDELBROT = 1,
	JULIA,
	BURNING_SHIP,
	CHROMOSOM,
	NOUN,
}				t_fractol;

typedef enum	e_mouse
{
	LEFT_CLICK = 1,
	SCROLL_UP = 5,
	SCROLL_DOWN = 4,
}				t_mouse;

typedef enum	e_keys
{
	TAB = 65289,
	ECHAP = 65307,
	SPACE = 32,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65361,
	LEFT = 65363,
	PLUS = 65451,
	MOIN = 65453,
	K_MULT = 65450,
	K_DIV = 65455,
	K_EQUA = 65469,
	ALPHA_NUM_1 = 49,
	ALPHA_NUM_2 = 50,
	ALPHA_NUM_3 = 51,
	ALPHA_NUM_4 = 52,
	ALPHA_NUM_5 = 53,
}				t_keys;

typedef struct	s_fimg
{
	void		*img;
	char		*data;
	int			sizeline;
	int			bpp;
	int			endian;
}				t_fimg;

#endif
