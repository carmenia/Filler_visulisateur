/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:11:04 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/24 14:24:22 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/filler_viz.h"

t_gslst	*gs_lstnew(t_game *game, int turn_switch)
{
	t_gslst *new;

	if ((new = (t_gslst *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	ft_bzero(new, sizeof(t_gslst));
	new->flags |= (turn_switch) ? TURN_SWITCH : 0;
	new->p1_pts = game->p1_rt;
	new->p2_pts = game->p2_rt;
	if (turn_switch == 0)
	{
		new->board = (char **)malloc((game->h + 1) * sizeof(char *));
		new->color_tab = (short *)malloc((game->h * game->w) * sizeof(short));
		ft_bzero(new->color_tab, (game->h * game->w) * sizeof(short));
	}
	return (new);
}

void	gs_lstadd(t_gslst **gss, t_gslst *new)
{
	if (gss && new)
	{
		if (*gss)
		{
			(*gss)->next = new;
			new->prev = *gss;
		}
		*gss = new;
	}
}
