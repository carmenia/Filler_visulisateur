/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_viz.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:30:14 by nmei              #+#    #+#             */
/*   Updated: 2018/09/24 14:21:14 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VIZ_H
# define FILLER_VIZ_H
# include <stddef.h>
# include "../libft/libft.h"
# define TURN_SWITCH	1
# define PLACED			2
# define P1_PLACED		4

typedef struct		s_gslst
{
	short			piece_w;
	short			piece_h;
	short			piece_x;
	short			piece_y;
	short			flags;
	int				turn;
	int				p1_pts;
	int				p2_pts;
	char			**board;
	short			*color_tab;
	char			**piece;
	struct s_gslst	*prev;
	struct s_gslst	*next;
}					t_gslst;

typedef struct		s_game
{
	char			*p1;
	char			*p2;
	int				turn_rt;
	int				h;
	int				w;
	int				p1_rt;
	int				p2_rt;
	short			*color_t_rt;
	t_gslst			*gss;
	t_gslst			*first;
	t_gslst			*last;
}					t_game;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				line_s;
	int				endian;
}					t_image;

typedef struct		s_envars
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	int				size;
	int				fd;
	int				p1_l;
	int				p2_l;
	int				b_glen;
	int				b_lpad;
	int				b_tpad;
	int				b_row_space;
	int				b_col_space;
	int				prev_turn;
	t_game			*g;
	t_gslst			*curr_gs;
	t_image			image;
}					t_envars;

int					idx(int row, int col, int dim);
double				ft_lint(double start, double end, double decimal_percent);
char				*board_strdup(t_game *game, int i, const char *s);

int					choose_board_color(t_envars *e, int row, int col);
int					choose_piece_color(t_envars *e, int row, int col);

void				disp_info(int mode);
void				setup_env(t_envars *env);

int					idx(int row, int col, int dim);
void				init_img(t_envars *env);
void				img_pixel_put(t_envars *env, double x, double y, int color);
void				clear_img(t_envars *env);

int					keydown_hook(int key, t_envars *env);
int					key_pressed_hook(int key, t_envars *env);

t_gslst				*gs_lstnew(t_game *game, int turn_switch);
void				gs_lstadd(t_gslst **gsts, t_gslst *new);

int					read_game(t_game *game, int fd, int argc, char *fpath);

void				render_scoreboard(t_envars *e, t_gslst *gs);
void				render_piece_pos(t_envars *e, t_gslst *gs);

void				render(t_envars *env);

#endif
