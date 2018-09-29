//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Map
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <irrlicht/irrlicht.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Game/Map.hpp"
#include "Bomberman.hpp"

Game::Map::Map(size_t size, size_t density)
	: _size(size)
{
	createMap();
	generateBlocks(density);
	_tmp = _map;
}

Game::Map::~Map()
{
	size_t y = 0;
	for (y = 1 ; y <= _size ; y++) {
		_map[y].clear();
		_tmp[y].clear();
	}
	_map.clear();
	_tmp.clear();
}

size_t	Game::Map::getSize()
{
	return _size;
}

void Game::Map::createMap()
{
	size_t		x = 0;
	size_t		y = 0;
	_map.resize(_size + 2);
	_map[0].append(_size + 2, '#');
	for (y = 1 ; y <= _size ; y++) {
		_map[y].push_back('#');
		for (x = 1 ; x <= _size ; x++) {
			if ((y % 2 == 0) && (x % 2 == 0))
				_map[y].push_back('#');
			else
				_map[y].push_back(' ');
		}
		_map[y].push_back('#');
	}
	_map[_size + 1].append(_size + 2, '#');
}

void	Game::Map::generateBlocks(size_t density)
{
	size_t x = 1;
	size_t y = 1;
	size_t nb = 0;
	srand((unsigned)time(0));
	for (y = 1 ; y <= _size ; y++) {
		for (x = 1 ; x <= _size ; x++) {
			if (!((((y == 1) || (y == _size)) &&
			       ((x <= 3) || (x >= _size - 2))) ||
			      (((x == 1) || (x == _size)) &&
			       ((y <= 3) || (y >= _size - 2)))) &&
			    (_map[y][x] == ' ')) {
				nb = (rand()%20)+1; 
				if (nb % density != 0 )
					_map[y][x] = 'X';
			}
		}
	}
}

void	Game::Map::resetMap()
{
	_map = _tmp;
}

size_t	Game::Map::getCase(size_t x, size_t y)
{
	return (_map[y][x]);
}

std::vector<std::string> &Game::Map::getMap()
{
	return (_map);
}

void	Game::Map::putMap()
{
	size_t y = 0;
	for (y = 0 ; y <= _size + 1 ; y++)
		puts(_map[y].c_str());
}

bool	Game::Map::isBlocked(size_t x, size_t y)
{
	if (_map[y][x] == ' ')
		return false;
	return true;
}

bool	Game::Map::moveCharacter(size_t player_nb, size_t x1, size_t y1, size_t x2, size_t y2)
{
	if (!isBlocked(x2, y2)) {	
		_map[y1][x1] = ' ';
		_map[y2][x2] = player_nb + 48;
		return true;
	}
	return false;
}

void Game::Map::deleteCharacter(size_t x, size_t y)
{
	if (_map[y][x] == '1' ||
	    _map[y][x] == '2' ||
	    _map[y][x] == '3' ||
	    _map[y][x] == '4')
		_map[y][x] = ' ';
}

void Game::Map::changeCase(size_t x, size_t y, char c)
{
	if ((x > 0 && x <= _size) &&
	    (y > 0 && y <= _size))
		if (_map[y][x] != '1' &&
		    _map[y][x] != '2' &&
		    _map[y][x] != '3' &&
		    _map[y][x] != '4' &&
		    _map[y][x] != '#')
			_map[y][x] = c;
}

bool	Game::Map::placeBomb(size_t x, size_t y)
{
	if (!isBlocked(x, y)) {
		_map[y][x] = 'o';
		return true;
	}
	return false;
}

bool	Game::Map::addPlayer(size_t player_nb)
{
	switch (player_nb) {
	case 1: _map[1][1] = '1';
		break;
	case 2: _map[1][_size] = '2';
		break;
	case 3: _map[_size][1] = '3';
		break;
	case 4: _map[_size][_size] = '4';
		break;
	default: return false;
	}
	return true;
}

bool Game::Map::addPlayer(size_t x, size_t y, size_t player_nb)
{
	_map[y][x] = player_nb + 48;
	return true;
}
