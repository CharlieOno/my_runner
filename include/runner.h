/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** header file with prototypes
*/

#ifndef __RUNNER_H__
#define __RUNNER_H__

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define	NB_SPRITE	44
#define	NB_CLOCK	18
#define	NB_MOB		8
#define	NB_SOUND	19

enum	objtype {PARRALAX, CHARACTER, ANIM, MOB, UI, MOBANIM};

typedef struct state_s {
	int 	*hex;
	int 	*mitty;
	int 	*rog;
	int 	*mob;
	int 	win;
	int 	mode;
	int 	defeated;
} state_t;

typedef struct prog_s {
	sfVideoMode		mode;
	sfClock			**clock;
	sfRenderWindow	*window;
	sfSound			**sound;
	int 			menu;
	int 			charac;
	char 			*map;
	float 			delay;
	char 			*text;
	state_t			state;
} prog_t;

typedef struct info_s {
	int 	maxhp;
	int 	hp;
	int 	atk;
	int 	exp;
	int 	lvl;
} info_t;

typedef struct object_s {
	enum objtype 		type;
	sfSprite			*obj;
	sfTexture			*img;
	sfVector2f			pos;
	sfIntRect			frame;
	sfRectangleShape 	*hit;
	info_t				stats;
} obj_t;

/* Menu Functions */
void	change_menu(prog_t *prog, obj_t **sprite, int select, int *selected);
void	menu_handling(obj_t **sprite, prog_t *prog, sfEvent event);
void	game_loop(obj_t **sprite, prog_t *prog, sfEvent event);
void	menu_loop(obj_t **sprite, prog_t *prog, sfEvent event);
void	cchoice_loop(obj_t **sprite, prog_t *prog, sfEvent event);
void	mchoice_loop(obj_t **sprite, prog_t *prog, sfEvent event);
void	menu_change(prog_t *prog, obj_t **sprite, int select, int *selected);
void	pause_change(obj_t **sprite, prog_t *prog, int select, int *selected);
void	cchoice_change(obj_t **sprite, prog_t *prog, int select, int *selectd);
void	mchoice_change(obj_t **sprite, prog_t *prog, int select, int *selectd);

/* Sound Functions */
void	sound_menu(prog_t *prog);
void	sound_game(prog_t *prog);
void	sound_character(prog_t *prog);
void	snd_char(prog_t *prog, obj_t **sprite, int i[2], int *state);
void	snd_anim(prog_t *prog, obj_t **sprite, int i[2], int *state);

/* Map Functions */
void	load_map(char *path, prog_t *prog);
void	buffer_to_map(prog_t *prog, char *line, int index);
void	init_map(prog_t *prog);
void	reset_map(prog_t *prog);

/* File Data Functions */
void	load_stats(obj_t *sprite, char *path);
void	save_stats(obj_t *sprite, char *path);

/* Game Engine Functions */
void	game_engine(prog_t *prog, obj_t **sprite);
void	engine_spawn(obj_t **sprite, prog_t *prog, int **index);
void	engine_hit(int *state, obj_t *sprite);
void	engine_deaths(prog_t *prog, obj_t **sprite);
void	engine_parsing_commands(obj_t **sprite, prog_t *prog, int *index);
void	engine_collision(prog_t *prog, obj_t **sprite);
void	engine_infinite(prog_t *prog, obj_t **sprite);
sfBool	check_collision(sfRectangleShape *rect1, sfRectangleShape *rect2);

/* CSFML Shortcuts */
void	sf_rect(sfSprite *sprite, sfIntRect frame);
void	sf_pos(sfSprite *sprite, sfVector2f vector);
void	sf_move(sfSprite *sprite, sfVector2f vector);
void	sf_draw(sfRenderWindow *window, sfSprite *sprite);

/* Setup Functions */
void 	setup(obj_t **sprite, prog_t *prog);
void 	setup_parralax(obj_t **sprite);
void 	setup_program(prog_t *prog);
void 	setup_engine(prog_t *prog);
void 	setup_mob_part1(obj_t **sprite);
void 	setup_mob_part2(obj_t **sprite);
void	setup_mob_part3(obj_t **sprite);
void 	setup_character_states(prog_t *prog);
void 	setup_hex(obj_t **sprite);
void 	setup_mitty(obj_t **sprite);
void 	setup_rog(obj_t **sprite);
void	setup_hitbox_characters(obj_t **sprite);
void	setup_hitbox_characters2(obj_t **sprite);
void	setup_hitbox_mob1(obj_t **sprite);
void 	setup_hitbox_mob2(obj_t **sprite);
void	setup_character_stats(obj_t **sprite);
void 	setup_menu(obj_t **sprite);
void	setup_menu2(obj_t **sprite);
void 	setup_pause(obj_t **sprite);
void	setup_gameui(obj_t **sprite);
void	setup_general_sounds(prog_t *prog);
void	setup_spell_sounds(prog_t *prog);

/* Reload Functions */
void	reload_game(prog_t *prog, obj_t **sprite);
void 	reload_characters(obj_t **sprite);
void 	reload_character_states(prog_t *prog);
void 	reload_engine(prog_t *prog);
void	reload_anim(prog_t *prog, obj_t **sprite);

/* Mob Animation Functions */
void	mob_truck(obj_t *car, sfClock *clock, int *state);
void	mob_car(obj_t *car, sfClock *clock, int *state);
void	mob_big(obj_t *big, sfClock *clock, int *state);
void	mob_geisha(obj_t *sprt, sfClock *clock, int *state);
void	mob_oldman(obj_t *sprt, sfClock *clock, int *state);
void	mob_ufo(obj_t *sprt, obj_t *fire, sfClock* clock[2], int *state);
void	mob_yeti(obj_t *yeti, obj_t *fire, sfClock* clock[2], int *state);
void	mob_cannon(obj_t *sprt, obj_t *fire, sfClock* clock[2], int *state);

/* Characters Animation Functions */
void 	hex_move(obj_t *hero, int speed);
void 	hex_shock(obj_t *hero, obj_t *anim, sfClock *clock, int *spell);
void 	hex_slide(obj_t *hero, sfClock *clock, int *anim);
void 	hex_walk(obj_t *hero, sfClock *clock, int *anim);
void 	hex_jump(obj_t *hero, sfClock *clock, int *anim);
void	hex_cast(int *start, obj_t *hero, obj_t *anim, int offset);
void	hex_hit(obj_t *hero, obj_t *anim, sfClock *clock, int *spell);
void	hex_shield(obj_t *hero, obj_t *anim, sfClock *clock, int *spell);

void 	mitty_walk(obj_t *hero, sfClock *clock, int *anim);
void 	mitty_move(obj_t *hero, int speed);
void 	mitty_jump(obj_t *hero, sfClock *clock, int *anim);
void 	mitty_slide(obj_t *hero, sfClock *clock, int *anim);
void 	mitty_fireball(obj_t *hero, obj_t *anim, sfClock *clock, int *spell);
void	mitty_cast(int *start, obj_t *hero, obj_t *anim, int offset);
void	mitty_octopus(obj_t *hero, obj_t *anim, sfClock *clock, int *hit);

void 	rog_walk(obj_t *hero, sfClock *clock, int *anim);
void 	rog_move(obj_t *hero, int speed);
void 	rog_jump(obj_t *hero, sfClock *clock, int *anim);
void	rog_jumping_logic(obj_t *hero, int state);
void	rog_dash(obj_t *hero, obj_t *efct, sfClock *clock, int *anim);
void	rog_firehit(obj_t *hero, sfClock *clock, int *anim);
void	rog_icehit(obj_t *hero, sfClock *clock, int *anim);
void	rog_smash(obj_t *hero, sfClock *clock, int *anim);
void	rog_buff(obj_t *hero, sfClock *clock, int *anim);

/* Core Animation Functions */
void	rog_sword_hitbox(prog_t *prog, obj_t **sprite);
void	game_animations(prog_t *prog, obj_t **sprite);
void	hex_animation(prog_t *prog, obj_t **sprite);
void	mitty_animation(prog_t *prog, obj_t **sprite);
void	rog_animation(prog_t *prog, obj_t **sprite);
void	mob_animation(prog_t *prog, obj_t **sprite);
void	dead_animation(prog_t *prog, obj_t *sprite, int *state);
void	hit_animation(obj_t *sprite, int value);
void 	parralax_right(obj_t *sprite, sfRenderWindow *window, float speed);

/* Events Functions */
void	hex_key_move(prog_t *prog);
void	hex_key_spell(prog_t *prog, obj_t **sprite);
void	rog_key_move(prog_t *prog, obj_t **sprite);
void	rog_key_spell(prog_t *prog, obj_t **sprite);
void	mitty_key_move(prog_t *prog);
void	mitty_key_spell(prog_t *prog, obj_t **sprite);
void	key_character(prog_t *prog, obj_t **sprite);
int 	navigation_menu_horizontal(int **select, int **selected, int x, int y);
int 	navigation_menu_vertical(int **select, int **selected, int x, int y);
void	game_events(prog_t *prog, obj_t **sprite, sfEvent event);
void	menu_events(prog_t *prog, sfEvent event, int *select, int *selected);
void	pause_events(prog_t *prog, sfEvent event, int *select, int *selected);
void	win_events(prog_t *prog, sfEvent event);
void	cchoice_events(prog_t *prog, sfEvent event, int *select, int *selectd);
void	mchoice_events(prog_t *prog, sfEvent event, int *select, int *selectd);

/* Draw Functions */
void	menu_draw_obj(prog_t *prog, obj_t **sprite, int select);
void	game_draw_obj(prog_t *prog, obj_t **sprite);
void	pause_draw_obj(prog_t *prog, obj_t **sprite, int select);
void	win_draw_obj(prog_t *prog, obj_t **sprite);
void	cchoice_draw_obj(prog_t *prog, obj_t **sprite);
void	mchoice_draw_obj(prog_t *prog, obj_t **sprite, int select);
void	alpha_characters(obj_t **sprite, int select);
void	draw_mapselect(prog_t *prog, int select);
void	draw_defeated(prog_t *prog, obj_t *blackbox);
void	draw_level(prog_t *prog, obj_t *entity);
void	draw_lifebar(prog_t *prog, obj_t **sprite, obj_t *entity);
void	draw_level_hp(prog_t *prog, obj_t **sprite);
void	draw_textbox(prog_t *prog, obj_t **sprite);
void	draw_hex(prog_t *prog, obj_t **sprite);
void	draw_mitty(prog_t *prog, obj_t **sprite);
void	draw_rog(prog_t *prog, obj_t **sprite);
void	draw_mob(prog_t *prog, obj_t **sprite);
sfText	*init_text(void);

void	dev_hitbox(prog_t *prog, obj_t **sprite);

/* Ressource Handling Functions */
obj_t	*create_object(const char *path, sfVector2f pos, sfIntRect rect,
	enum objtype given_type);
sfRectangleShape 	*create_hitbox(sfVector2f size, sfColor color);
void	update_hitbox(obj_t *sprite, sfVector2f off);
void	exclude_hitbox(obj_t **sprite);
void	destroy_object(obj_t *sprite);
void	init_stats(obj_t *sprite, int hp, int atk, int exp);
void	check_level_up(prog_t *prog, obj_t *sprite);
void	generate_mob_stats(obj_t **sprite, int state, int level);
void	generate_mob_stats2(obj_t **sprite, int state, int level);
void	remove_hp(obj_t *sprite, int dmg);
int 	**create_state_list(void);
void	add_exp(prog_t *prog, obj_t **sprite, int *state, obj_t *actual);
void	update_spell_dmg(obj_t *player, obj_t *spell);
char	*my_getchar(int nbr);
int 	my_getnbr(char *str);
int 	nbr_length(int nbr);
void	buff_hex_shield(prog_t *prog, obj_t *hex);
void	rog_heal(obj_t *sprite);
int 	*generate_exp_table(void);

#endif