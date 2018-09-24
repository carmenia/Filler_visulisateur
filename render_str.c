/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:27:11 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/24 12:27:14 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "includes/filler_viz.h"

void	render_scoreboard(t_envars *e, t_gslst *gs)
{
	int		end;
	char	*p1;
	char	*p2;

	end = (ft_strlen(e->g->p1) > ft_strlen(e->g->p2)) ? 
		(ft_strlen(e->g->p1) + 1) * e->b_glen :
		(ft_strlen(e->g->p2) + 1) * e->b_glen;
	p1 = ft_itoa(gs->p1_pts);
	p2 = ft_itoa(gs->p2_pts);
	mlx_string_put(e->mlx, e->win, e->b_lpad, 10, 0xFF0000, e->g->p1);
	mlx_string_put(e->mlx, e->win, e->b_lpad + end, 10, 0xFF0000, p1);
	mlx_string_put(e->mlx, e->win, e->b_lpad, 30, 0x0000FF, e->g->p2);
	mlx_string_put(e->mlx, e->win, e->b_lpad + end, 30, 0x0000FF, p2);
	free(p1);
	free(p2);
}

void	render_piece_pos(t_envars *e, t_gslst *gs)
{
	int		x_start;
	char	*x;
	char	*y;
	char	*p_str;
	int		p_len;

	x_start = e->b_lpad + (e->g->w + 1) * e->b_glen;
	if (gs->prev)
	{
		x = ft_itoa(gs->prev->piece_x);
		y = ft_itoa(gs->prev->piece_y);
		p_len = ft_strlen(x) + ft_strlen(y) + ft_strlen("Placed at: , ");
		p_str = (char *)malloc(p_len + 1);
		p_str = ft_strcat(ft_strcat(ft_strcat(p_str, "Placed at: "), x), ", ");
		p_str = ft_strcat(ft_strcat(p_str, y), "\0");
		if (gs->prev->flags & P1_PLACED)
			mlx_string_put(e->mlx, e->win, x_start, 10, 0xFFA500, p_str);
		else
			mlx_string_put(e->mlx, e->win, x_start, 10, 0x00A5FF, p_str);
		free(x);
		free(y);
		free(p_str);
	}
	mlx_string_put(e->mlx, e->win, x_start, 30, 0xFFFFFF, "Next Piece:");
}
