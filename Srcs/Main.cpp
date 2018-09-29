/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
#include <Menu/Menu.hpp>
#include "Engine/EventReceiver.hpp"
#include "Engine/Engine.hpp"
#include "Renderer/Renderer.hpp"
#include "Bomberman.hpp"

#include "Game/Game.hpp"
#include "Game/Bomb.hpp"
#include "Game/Character.hpp"
#include "Game/Map.hpp"

#include "Menu/Menu.hpp"

int 	main(void)
{
	Engine::Engine		*engine = Engine::Engine::instance();
	RR::Renderer		renderer(*engine);
	Game::Game		*game = nullptr;
	Menu::Menu		menu;
	bool 			rendererInit= false;

	while(engine->keepLooping()) {
		if (game) {
			if (!rendererInit) {
				renderer.init(game->getMap(),
					game->getMapSize(),
					game->getPlayers());
				rendererInit = true;
			}
			if (engine->getDevice()->isWindowActive()) {
				size_t nb_winner = game->loop(*engine);
				if (nb_winner != Game::NO_WINNER) {
					renderer.gameover(nb_winner);
				} else {
					renderer.render(game->getMap(),
						game->getMapSize(),
						game->getPlayers());
				}
			}
		} else {
			game = menu.getSelectedGame();
		}
	}
	if (game)
		engine->saveGame(game->getMap().getMap());
	engine->drop();
	return (RT_SUCCESS);
}
