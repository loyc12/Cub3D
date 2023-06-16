/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:56:01 by llord             #+#    #+#             */
/*   Updated: 2023/06/16 12:01:27 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "structs.h"

// ======== FUNCTIONS ======== //

//from 0_checkers --- (5)
bool			is_char_valid(char c);
bool			is_map_start(int i);
void			check_assets(void);
bool			is_colour_valid(int v);
void			check_colours(void);

//from 0_coorders --- (4)
t_coords		*coords_copy(t_coords *_c);
t_vector		*coords_to_vector(t_coords	*_c);
void			flood_check(t_tile *tile);
void			flood_check_map(void);

//from 0_initializers --- (5)
void			init_player(void);
void			init_window(void);
void			check_map(void);
void			init_map(void);
void			init_game(int ac, char **av);

//from 0_readers --- (2)
void			read_file(int fd);
void			read_level(char *path);

//from 1_maths.c  --- (4)
void			find_ratios(t_ray *r);
double			normalize_angle(double angle);
uint32_t		get_rgba(t_colour *c, double scale);
double			set_precision(double value, long precision);

//from 1_raycasters --- (5)
int				find_hit_type(t_ray *r);
void			find_first_ray_dists(t_ray *r);
bool			evaluate_x_hits(t_ray *r);
bool			evaluate_y_hits(t_ray *r);
t_slice			*cast_ray(t_vector *pos, double ray_angle);

//from 2_actions --- (5)
void			key_esc(void);
void			move_towards(double angle);
void			turn_left(void);
void			turn_right(void);

//from 2_hookers  --- (2)
void			apply_movements(t_master *data);
void			loop_hook(void *param);
void			key_hook(mlx_key_data_t keydata, void *param);

//from 2_movers  --- (3)
int				get_tile_type(double x, double y);
int				check_colision(t_entity *e, double dx, double dy);
void			move_entity(t_entity *e, double angle);

//from 3_slicers --- (4)
void			draw_square(uint32_t x, uint32_t y, t_colour *c, double f);
void			draw_slice(t_master *d, t_slice *slice, int screen_pos);
t_slice			*create_slice(t_ray *r, double angle);
void			make_canvas(void);

//from 3_tilers --- (4)
t_tile			*create_tile(char c, t_coords *_coords);
t_tile			*find_tile(int x, int y);
void			build_map(t_master *data);
void			connect_map(void);

//from 3_getters --- (4)
int				get_next_num(char *line, int *i);
void			get_colour(char *line, t_colour **c);
void			get_texture(char *line, char **path);
void			get_info(void);

//from freeers --- (4)
void			free_tiles(t_master *data);
void			free_entity(t_entity *entity);
int				free_master(void);
void			close_with_error(char *err);

//from main
t_master		*get_master(void);
void			play_game(t_master *data);
int				main(int ac, char **av);

//from textures
mlx_texture_t	*make_texture(char *path);
void			find_texture_pos(t_ray *r);
t_colour		get_texture_colour(t_slice *s, double h);

#endif //	FUNCS_H
