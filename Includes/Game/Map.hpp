/*
** EPITECH PROJECT, 2018
** Indie Studio - Game - Map
** File description:
** Created by Hadrien Mortier on 5 June 2018
*/


#ifndef MAP_HPP
#define MAP_HPP
#include <irrlicht/irrlicht.h>
#include <vector>
#include <string>

// Map's Size
constexpr unsigned SMALL = 9;
constexpr unsigned MEDIUM = 13; // By default
constexpr unsigned BIG = 17;

// Density of destructibles Blocks
constexpr unsigned DENSITY_LOW = 3;
constexpr unsigned DENSITY_MEDIUM = 5;
constexpr unsigned DENSITY_HIGH = 8;
constexpr unsigned DENSITY_MAX = 11;

namespace Game {
	class Map {

	public:
		Map(size_t size, size_t density);
		~Map();
		size_t getSize();
		void createMap();
		void generateBlocks(size_t density);
		void resetMap();
		size_t getCase(size_t x, size_t y);
		std::vector<std::string> &getMap();
		void putMap();
		void deleteCharacter(size_t x, size_t y);
		bool isBlocked(size_t x, size_t y);
		bool moveCharacter(size_t player_nb, size_t x1, size_t y1, size_t x2, size_t y2);

		bool placeBomb(size_t x, size_t y);
		void changeCase(size_t x, size_t y, char c);

		bool addPlayer(size_t player_nb);
		bool addPlayer(size_t x, size_t y, size_t player_nb);
	private:
		size_t				_size;
		std::vector<std::string>	_map;
		std::vector<std::string>	_tmp;
	};
}

#endif // GAME_HPP
