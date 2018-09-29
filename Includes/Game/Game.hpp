//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Game
// File description:
// Created by Hadrien Mortier on 5 June 2018
//

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"
#include "Game/Character.hpp"
#include "Game/Map.hpp"

namespace Game {
	constexpr size_t NO_WINNER = 5;
	class Game {
	public:
		Game(size_t nbPlayer, size_t mapSize, size_t density);
		~Game();
		Map &getMap();
		size_t	loop(Engine::Engine &engine);
		size_t getMapSize();
		Character getPlayer(size_t nb);
		std::vector<Character *> getPlayers();
	private:
		Map				_map;
		std::vector<Character *>	_player;
	};
}

#endif // GAME_HPP
