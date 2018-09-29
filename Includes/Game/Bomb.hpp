//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Bomb
// File description:
// Created by Hadrien Mortier on 7 June 2018
//

#ifndef BOMB_HPP
#define BOMB_HPP

#include <vector>
#include <ctime>
#include <irrlicht/irrlicht.h>
#include "Game/Map.hpp"

constexpr unsigned DEFAULT_TIMER = 3; // in seconds
constexpr unsigned DEFAULT_RANGE = 3; // in map cases
constexpr unsigned DEFAULT_DAMAGE = 35; // in health points

namespace Game {
	class Character;
	class Bomb {
	public:
		Bomb(Game::Map &map);
		~Bomb();
		bool placeBomb(size_t x, size_t y);
		void explodes(std::vector<Character *> players);
		void replaceFlames(char c, std::vector<Character *> players);
		bool isActivated();
	protected:
		Map		&_map;	// Playing map
		size_t		_x;	// X Position
		size_t		_y;	// Y Position
		std::time_t	_time;
		bool		_activated;
	};
}

#endif // BOMB_HPP
