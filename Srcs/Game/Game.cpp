//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Game
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <irrlicht/irrlicht.h>
#include "Game/Game.hpp"
#include "Bomberman.hpp"

Game::Game::Game(size_t nbPlayer, size_t mapSize, size_t density)
	: _map(mapSize, density)
{
	bool human2 = true;
	_player.push_back(new Character(_map, 1, true));
	if (nbPlayer == 1)
		human2 = false;
	_player.push_back(new Character(_map, 2, human2));
	_player.push_back(new Character(_map, 3, false));
	_player.push_back(new Character(_map, 4, false));
}

Game::Game::~Game()
{
	for (Character *player : _player) {
		delete(player);
	}
}

size_t Game::Game::loop(Engine::Engine &engine)
{
	_player[0]->move(engine);
	_player[0]->testBomb(_player);
	if (engine.getEventReceiver()->isKeyDown(irr::KEY_SPACE))
		_player[0]->placeBomb();
	if (_player[1]->isHuman()) {
		_player[1]->move(engine, 1);
		_player[1]->testBomb(_player);
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_X))
			_player[1]->placeBomb();
	}
	size_t maxHuman = _player[1]->isHuman() ? 2 : 1;
	for (size_t i = 0 ; i < maxHuman ; i++) {
		size_t y = 0;
		bool playerAlone = true;
		for (Character *player2 : _player) {
			if (!player2->isDead() && i != y)
				playerAlone = false;
			y++;
		}
		if (playerAlone)
			return i;
	}
	if (_player[0]->isDead() && (_player[1]->isDead() || !_player[1]->isHuman()))
		return 3;
	return NO_WINNER;
}

Game::Character Game::Game::getPlayer(size_t nb)
{
	return *_player[nb];
}

std::vector<Game::Character *> Game::Game::getPlayers()
{
	return (_player);
}

Game::Map &Game::Game::getMap()
{
	return _map;
}

size_t Game::Game::getMapSize()
{
	return _map.getSize();
}
