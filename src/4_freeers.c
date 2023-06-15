/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_freeers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:55:54 by llord             #+#    #+#             */
/*   Updated: 2023/06/15 10:59:35 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//tries to free every tile
void	free_tiles(t_master *data)
{
	int		i;

	if (data->tiles)
	{
		i = -1;
		while (data->tiles[++i])
		{
			//free the stuff inside the tiles here
			ft_free_null(ADRS data->tiles[i]->coords);
			ft_free_null(ADRS data->tiles[i]);
		}
		ft_free_null(ADRS data->tiles);
	}
}

void	free_entity(t_entity *entity)
{
	if (entity)
	{
		ft_free_null(ADRS entity->vector);
		ft_free_null(ADRS entity);
	}
}

//tries to free everything and returns t_master state
int	free_master(void)
{
	t_master	*data;
	int			state;

	data = get_master();
	state = data->master_state;

	//free the stuff inside d here

	free_tiles(data);
	free_entity(data->player);

	ft_free_null(ADRS data->level);
	ft_free_null(ADRS data->c_ceiling);
	ft_free_null(ADRS data->c_floor);
	ft_free_array(ADRS2 data->t_paths);
//	if (data->window)
//		mlx_terminate(data->window);
//void mlx_delete_texture(mlx_texture_t* texture);
	ft_free_null(ADRS data); //		MUST BE LAST FREED
	return (state);
}

//frees all and exits
void	close_with_error(char *err)
{
	ft_puterr(err);
	printf("\n");
	get_master()->master_state = MSTATE_ERROR;
	exit (free_master());
}
