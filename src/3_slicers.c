/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_slicers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:57:50 by llord             #+#    #+#             */
/*   Updated: 2023/06/16 12:03:40 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//draws a macro pixel on the screen (0:0 is at the bottom right of the center)
void	draw_square(uint32_t x, uint32_t y, t_colour *c, double f)
{
	uint32_t	dx;
	uint32_t	dy;

	x = (PIXEL_SIZE * x) + (SCREEN_WIDTH / 2);
	y = (PIXEL_SIZE * y) + (SCREEN_HEIGHT / 2);
	dy = 0;
	while (dy < PIXEL_SIZE)
	{
		dx = 0;
		while (dx < PIXEL_SIZE)
		{
			mlx_put_pixel(get_master()->canvas, (x + dx), (y + dy), get_rgba(c, f));
			dx++;
		}
		dy++;
	}
}

//draws a macro pixel vertical line on the scr (0 is at the right of the center)
void	draw_slice(t_master *d, t_slice *slice, int screen_pos)
{
	t_colour	c;
	int			y;
	int			wall_y;
	double		floor_shade;
	double		wall_shade;

	wall_shade = (S_FACTOR / (2 * (slice->dist + 1))) + (1 - (S_FACTOR / 2));
	y = -((d->half_height) + 1);
	while (++y < d->half_height)
	{
		floor_shade = fabs((double)y / (double)d->half_height * \
			S_FACTOR) + (1 - S_FACTOR);
		wall_y = slice->size * d->half_height;
		if (-wall_y <= y && y < wall_y)
		{
			c = get_texture_colour(slice, (double)(y + wall_y) / (2 * wall_y));
			draw_square(screen_pos, y, &c, wall_shade);
		}
		else if (y < 0)
			draw_square(screen_pos, y, d->c_ceiling, ((2 - S_FACTOR) - floor_shade));
		else
			draw_square(screen_pos, y, d->c_floor, floor_shade);
	}
	ft_free_null(ADRS slice);
}

t_slice	*create_slice(t_ray *r, double angle)
{
	t_slice	*slice;

	slice = ft_calloc(1, sizeof(t_slice));
	if (r->hit_type == TTYPE_ERROR)
	{
		slice->size = 0;
		return (ft_free_null(ADRS r), slice);
	}
	slice->hit_tile = r->hit_tile;
	slice->dist = r->ray_dist * cos(M_PI * angle / 180);
	slice->size = set_precision(1 / slice->dist, 1073741824);
	slice->hit_type = r->hit_type;
	slice->hit_dir = r->hit_dir;
	slice->texture_pos = r->wall_pos;
	ft_free_null(ADRS r);
	return (slice);
}

//initializes the background (canvas) to draw on
void	make_canvas(void)
{
	t_master	*d;
	int			canvas_colour[4];

	canvas_colour[0] = 0;
	canvas_colour[1] = 0;
	canvas_colour[2] = 0;
	canvas_colour[3] = 255;
	d = get_master();
	d->canvas = mlx_new_image(d->window, SCREEN_WIDTH, SCREEN_HEIGHT);
	ft_memfset(d->canvas->pixels, canvas_colour, SCREEN_WIDTH
		* d->canvas->height * BPP, 4);
	mlx_image_to_window(d->window, d->canvas, 0, 0);
}
