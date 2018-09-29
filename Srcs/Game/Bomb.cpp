//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Bomb
// File description:
// Created by Hadrien Mortier on 7 June 2018
//

#include <irrlicht/irrlicht.h>
#include "Game/Bomb.hpp"
#include "Bomberman.hpp"
#include "Game/Character.hpp" // have to be rest

Game::Bomb::Bomb(Game::Map &map)
	: _map(map), _activated(false)
{
}

Game::Bomb::~Bomb()
{
}

bool	Game::Bomb::placeBomb(size_t x, size_t y)
{
	if (_map.placeBomb(x, y)) {
		_x = x;
		_y = y;
		_time = std::time(nullptr);
		_activated = true;
		return true;
	}
	return false;
}

void	Game::Bomb::replaceFlames(char c, std::vector<Character *> players)
{
	size_t i = 1;
	char on = 0;
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		on = _map.getCase(_x, _y - i);
		if (on == '#')
			break;
		else if (on >= '1' && on <= '4') 
			players[on - '1']->loseHP(DEFAULT_DAMAGE);
		_map.changeCase(_x, _y - i, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		on = _map.getCase(_x, _y + i);
		if (on == '#')
			break;
		else if (on >= '1' && on <= '4')
			players[on - '1']->loseHP(DEFAULT_DAMAGE);
		_map.changeCase(_x, _y + i, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		on = _map.getCase(_x - i, _y);
		if (on == '#')
			break;
		else if (on >= '1' && on <= '4')
			players[on - '1']->loseHP(DEFAULT_DAMAGE);
		_map.changeCase(_x - i, _y, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		on = _map.getCase(_x + i, _y);
		if (on == '#')
			break;
		else if (on >= '1' && on <= '4')
			players[on - '1']->loseHP(DEFAULT_DAMAGE);
		_map.changeCase(_x + i, _y, c);
	}
}

void	Game::Bomb::explodes(std::vector<Character *> players)
{
	if (_time + 3 < std::time(nullptr)) {
		_map.changeCase(_x, _y, 'O');
		replaceFlames('O', players);
	}
	if (_time + 4 < std::time(nullptr)) {
		_map.changeCase(_x, _y, ' ');
		_activated = false;
		replaceFlames(' ', players);
	}
}

bool	Game::Bomb::isActivated()
{
	return _activated;
}
