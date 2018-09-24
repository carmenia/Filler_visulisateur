/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:10:36 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/24 14:23:26 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler_viz.h"

int			choose_board_color(t_envars *e, int row, int col)
{
	t_game	*g;
	t_gslst	*gs;
	int		color;

	gs = e->curr_gs;
	g = e->g;
	color = 0;
	if (gs->board[row][col] == '.')
		color = 0xD3D3D3;
	else if (gs->board[row][col] == 'O')
		color = 0xFF6666;
	else if (gs->board[row][col] == 'o')
		color = 0xFF0000;
	else if (gs->board[row][col] == 'X')
		color = 0x66b2ff;
	else if (gs->board[row][col] == 'x')
		color = 0x0000ff;
	return (color);
}

int			choose_piece_color(t_envars *e, int row, int col)
{
	int		color;
	t_gslst	*gs;

	gs = e->curr_gs;
	color = 0;
	if (gs->piece[row][col] == '.')
		color = 0xFFFFFF;
	else if (gs->piece[row][col] == '*')
	{
		if (gs->flags & P1_PLACED)
			color = 0xFFA500;
		else
			color = 0x00A5FF;
	}
	return (color);
}
