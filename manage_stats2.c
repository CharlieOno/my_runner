/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** part 2 of manage stats file
*/

#include "runner.h"

void	check_level_up(prog_t *prog, obj_t *sprite)
{
	static int 	*exp_table = NULL;

	exp_table = (exp_table == NULL) ? generate_exp_table() : exp_table;
	if (sprite->stats.lvl == 80)
		return;
	if (exp_table[sprite->stats.lvl - 1] < sprite->stats.exp) {
		sprite->stats.exp -= exp_table[sprite->stats.lvl - 1];
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
		sfSound_play(prog->sound[11]);
	}
}

void	buff_hex_shield(prog_t *prog, obj_t *hex)
{
	sfTime 	current_time = sfClock_getElapsedTime(prog->clock[17]);
	static int 	state = 0;
	static int 	hp = 0;

	state = (!prog->state.hex[3]) ? 0 : state;
	if (!prog->state.hex[3])
		return;
	if (state == 0) {
		state = 1;
		hp = hex->stats.hp;
		sfClock_restart(prog->clock[17]);
	}
	if (sfTime_asSeconds(current_time) < 0.4)
		hex->stats.hp = hp;
}

void	update_spell_dmg(obj_t *player, obj_t *spell)
{
	while (player->stats.lvl > spell->stats.lvl) {
		spell->stats.lvl += 1;
		spell->stats.atk += player->stats.atk / 10;
	}
}