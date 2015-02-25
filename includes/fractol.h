/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:19:54 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:22:19 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define UI_COLOR ROUGE
# define ZOOM 1.0100
# define SIZE_H 600
# define SIZE_W 600
# define PUT_W mlx_string_put
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "keys_n_cols.h"
# include "mlx_int.h"

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_dpos
{
	double		x;
	double		y;
}				t_dpos;

typedef struct	s_env
{
	void		*mlx;
}				t_env;

typedef struct	s_square
{
	int			max_iter;
	int			zoom;
}				t_square;

typedef	struct	s_hud
{
	void		*win;
}				t_hud;

typedef struct	s_fractal
{
	void		*win;
	t_dpos		p1;
	t_dpos		p2;
	t_dpos		offset;
	int			x;
	int			y;
	double		zoom;
	double		max_iter;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	t_fimg		img;
	int			statut;
	int			refresh;
	int			stop_mouse;
	int			which_fractal;
	void		(*ft_pros)(struct s_fractal *p, int x, int y);
	int			(*ft_color)(int i);
}				t_fractal;

typedef struct	s_global
{
	t_env		e;
	t_fractal	p;
	t_fractal	p2;
	t_hud		hud;
	t_fractal	*cur;
}				t_global;
/*
** main.c
*/
int				parse_params(char **av);
int				choose_fractol(t_fractal *p, char *str);
/*
** inits.c
*/
void			init_color(t_fractal *p);
void			init_point(t_fractal *p);
void			init_monitory(int two_win);
void			init_mlx(int two_win);
void			init_all(void);
/*
** displays.c
*/
void			mlx_string_put2(void *win, int x, int y, int color, char *str);
char			*display_fractal_name(t_fractal *p);
char			*check_mouse(int stop_mouse);
void			display_ui_textp2(void *win);
void			display_ui_text(void *win);
/*
** update.c
*/
void			update_brot(t_fractal *cur);
void			first_display_secwin(int *i);
void			handle_second_win(void);
/*
** ft_julia_mandelbrot.c
*/
void			init_g_julia(t_fractal *p);
void			init_g_mandelbrot(t_fractal *p);
void			ft_pros_julia(t_fractal *p, int x, int y);
void			ft_pros_mandelbrot(t_fractal *p, int x, int y);
/*
** inits_rabbit_chromo.c
*/
void			ft_pros_chromosom(t_fractal *p, int x, int y);
void			ft_pros_noun(t_fractal *p, int x, int y);
void			init_g_chromosom(t_fractal *p);
void			init_g_noun(t_fractal *p);
/*
** mouse_hooks.c
*/
void			select_win(t_fractal *p);
int				mouse_hook(int x, int y, t_fractal *p);
int				mouse2_hook(int button, int x, int y, t_fractal *p);
/*
** llitoa.c
*/
char			*ft_llitoa(long long int nb);
/*
** hooks.c
*/
int				expose_hook(t_fractal *p);
int				loop_hook(t_fractal **p);
int				key_hook(int keycode, t_fractal *p);
int				expose_hook_m_a(void);
/*
** color.c
*/
int				ft_change_color(int i);
int				ft_change_color2(int i);
int				ft_change_color3(int i);
int				ft_change_color4(int i);
int				ft_change_color5(int i);
/*
** misc.c
*/
t_global		*g(void);
void			exit_free(void);
void			ft_error(int er);
char			*ft_strlower(char *str);
void			inc_vector(double *point, double vector);
void			ft_put_img_pix(t_fimg *img, int x, int y, int color);

#endif
