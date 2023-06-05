/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:55:54 by llord             #+#    #+#             */
/*   Updated: 2023/06/05 11:15:37 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
creates the t_master *d struct (first call behaviour)*/
t_master	*get_master(void)
{
	static t_master	*data;

	if (!data)
		data = ft_calloc(1, sizeof(t_master));

	return (data);
}

/*
verifies the inputs (arguments and level file) are valid*/
void	check_inputs(int ac)
{
	if (ac != 2)
		close_with_error(ERR_ARG_COUNT);
}

int	main(int ac, char **av)
{
	t_master	*data;

	data = get_master();
	check_inputs(ac); //			verifies the inputs (argument count) are valid
	read_level(av[1]); //			opens the .cub file and copies its contents into d.level

	printf(">%s<\n\n", data->level); //	0============ DEBUG ============0

	init_map(); //					creates the map grid from the map-info contained in d.level

//	print_tiles(); //					0============ DEBUG ============0

//	...

	printf("\n");

	return (free_master());
}


/*

use // in front of the line to mark what is completed


//	data = get_master() //	creates the t_master *d struct (first call behaviour)

//	check_inputs() //		verifies the inputs (arguments and level file) are valid

	read_level() //			opens the .cub file and copies its contents into d.level
//		read_file() //			copies the .cub file's contents into d.level
//		get_info() //			collects and voids the non-map info from d.level
		check_info() //			verifies the texture paths and floor/ceiling colours

//	init_map() //			creates the map grid from the map-info contained in d.level
//		check_map() //			verifies each map character and the total map lenght
//		build_map()				creates the unconnected tiles for the map grid
//		connect_map() //		connects all the map's tiles into a tile grid
//		check_flood_fill()		verifies that the map is closed
		init_player() //		creates the player's entity

	init_window()
		init_mlx()
		get_textures()
		check_textures()
		open_window()

	game_loop()
	{
		...
		if (...)
			close_game()
	}

	t_master {

		char		*level
		t_colour	colour x 2
		char		*texture x 4
		char		*last_line_read

	}




*/

