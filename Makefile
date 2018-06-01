##
## EPITECH PROJECT, 2017
## makefile
## File description:
## c
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -pedantic

CFLAGS	+=	-L ../.graphic_programming/lib/

CFLAGS	+=	-I ../.graph_programming/include/SFML/

CFLAGS	+=	-I ./include/

CFLAGS	+=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

#LIB	=	-lm -lc_graph_prog

NAME	=	my_runner

SRC	=	main.c 						\
		atoi_itoa.c 				\
		shortcut_csfml_functions.c 	\
		sound_theme.c 				\
		sound_character.c 			\
		setup.c 					\
		setup_ui.c 					\
		setup_characters.c 			\
		setup_mob.c 				\
		setup_hitbox.c 				\
		setup_sound.c 				\
		reload_game.c 				\
		event_handling.c 			\
		event_menu.c 				\
		event_misc.c 				\
		event_rog.c 				\
		manage_ressource.c 			\
		manage_stats.c 				\
		manage_stats2.c 			\
		generate_mob_stats.c 		\
		generate_mob_stats2.c 		\
		menu_handling.c 			\
		menu_handling2.c 			\
		menu_change.c 				\
		draw_handling.c 			\
		draw_handling2.c 			\
		draw_characters.c 			\
		draw_misc.c 				\
		draw_ui.c 					\
		draw_ui2.c 					\
		engine_main.c 				\
		engine_file_handler.c 		\
		engine_stats.c 				\
		engine_parsing.c 			\
		engine_collision.c 			\
		engine_infinite.c 			\
		animation_handling.c 		\
		animation_characters.c 		\
		animation_mob.c 			\
		animation_mob2.c 			\
		animation_mob3.c 			\
		animation_mob4.c 			\
		animation_rog.c 			\
		animation_rog2.c 			\
		animation_rog3.c 			\
		animation_mitty.c 			\
		animation_mitty2.c 			\
		animation_hex.c 			\
		animation_hex2.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	export LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export LD_LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export CPATH=$CPATH:/home/charlieono/.graph_programming/include
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
