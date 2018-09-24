/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:26:26 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/24 14:44:30 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "includes/filler_viz.h"

void			disp_info(int mode)
{
	if (mode == 0)
	{
		write(2, "\nUsage error: please verify input format is either:", 51);
		write(2, "\n./filler_viz [filler_vm_output] ", 33);
		write(2, "\nOR\nfiller_vm [vm_options] | ./filler_viz\n\n", 43);
		exit(1);
	}
	else if (mode == 1)
	{
		write(2, "An error occurred reading the file or input.\n", 45);
		write(2, "Please verify that it is valid\n", 31);
		exit(1);
	}
	else if (mode == 2)
	{
		ft_printf("\n		Ceci est un visualisateur dans le cadre \
du projet Filler de 42\n\n\
		Pour naviguer dans la fenetre, utiliser les commandes suivantes:\n\
		fleche de gauche: aller en arriere d'un tour\n\
		fleche de droite: aller en avant d'un tour\n\
		fleche du haut: avancer de 9 tours\n\
		fleche du bas: reculer de 9 tours\n\
		p: Imprimer le plateau courant sur le terminal\n\
		f: Retour au debut de la partie\n\
		l: Avancer jusqu'a la fin de la partie\n\
		esc ou q: Quitter la fenetre\n\n");
	}
}

void			setup_env(t_envars *e)
{
	e->b_glen = 12;
	e->b_lpad = e->b_glen;
	e->b_tpad = 70;
	e->b_row_space = 1;
	e->b_col_space = 1;
	e->w = ((e->g->w + 1) * e->b_glen + e->b_lpad) * 2;
	e->h = (e->g->h + 1) * e->b_glen + e->b_tpad;
	e->size = e->w * e->h;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w, e->h, "Visualisteur Filler 42");
	e->prev_turn = -1;
	init_img(e);
	mlx_key_hook(e->win, keydown_hook, e);
	mlx_hook(e->win, 2, 0, key_pressed_hook, e);
}

int				main(int argc, const char *argv[])
{
	t_envars	env;
	t_game		game;

	if (argc == 1 || argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (read_game(&game, env.fd, argc, (char *)argv[1]) == 0)
		{
			disp_info(2);
			env.g = &game;
			env.curr_gs = game.first;
			setup_env(&env);
			render(&env);
			mlx_loop(env.mlx);
			return (0);
		}
		else
			disp_info(1);
	}
	disp_info(0);
}
