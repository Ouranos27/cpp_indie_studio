//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
#include "Game/Character.hpp"
#include "Bomberman.hpp"

Game::Character::Character(Game::Map &map, size_t nb, bool human)
	: _map(map), _bomb(map), _nb(nb), _hp(DEFAULT_HP), _human(human)
{
	size_t size = _map.getSize();
	switch (nb) {
        case 1: _x = 1;
		_y = 1;
		_direction = Game::Character::Oriented::DOWN;
	        break;
        case 2: _x = size;
		_y = 1;
		_direction = Game::Character::Oriented::LEFT;
                break;
        case 3: _x = 1;
		_y = size;
		_direction = Game::Character::Oriented::UP;
		break;
        case 4: _x = size;
		_y = size;
		_direction = Game::Character::Oriented::RIGHT;
                break;
        }
	_map.addPlayer(_x, _y, nb);
	// if (!_human)
	//	startIA();
}

Game::Character::~Character()
{
}

bool Game::Character::isHuman()
{
	return _human;
}

Game::Character::Oriented Game::Character::getDirection()
{
	return _direction;
}

size_t Game::Character::getHP()
{
	return _hp;
}

size_t Game::Character::getScore()
{
	return _score;
}

void Game::Character::placeBomb()
{
	size_t x = _x;
	size_t y = _y;
	switch (_direction) {
        case Game::Character::Oriented::UP :
		y -= 1;
                break;
        case Game::Character::Oriented::DOWN :
                y += 1;
		break;
	case Game::Character::Oriented::RIGHT :
		x += 1;
		break;
	case Game::Character::Oriented::LEFT :
		x -= 1;
		break;
	}
	if (!_bomb.isActivated())
		_bomb.placeBomb(x, y);
}

void Game::Character::testBomb(std::vector<Character *> player)
{
	if (_bomb.isActivated())
		_bomb.explodes(player);
}

void	Game::Character::deleteCharacter()
{
	_map.deleteCharacter(_x, _y);
}

bool Game::Character::loseHP(size_t damages)
{
	if (_lastDamage + 2 < std::time(nullptr)) {
		if (damages >= _hp || _hp > 100 || _hp == 0) {
			deleteCharacter();
			_hp = 0;
			return true;
		} else {
			_hp -= damages;
		}
		_lastDamage = std::time(nullptr);
	}
	return false;
}

bool Game::Character::isDead()
{
	return _hp == 0;
}

bool Game::Character::move(Engine::Engine &engine)
{
	if (_hp > 0) {
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_UP))
			return moveUp();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_DOWN))
			return moveDown();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_LEFT))
			return moveRight();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_RIGHT))
			return moveLeft();
	}
	return false;
}

bool Game::Character::move(Engine::Engine &engine, int i)
{
	if (_hp > 0) {
		if (i == -1)
			i = i + 1;
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_Z) ||
			engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_W))
			return moveUp();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_S))
			return moveDown();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_Q) ||
			engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_A))
			return moveRight();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_D))
			return moveLeft();
	}
	return false;
}

bool Game::Character::moveUp()
{
	if (_hp > 0) {
		if (_direction == Game::Character::Oriented::UP)
			if (_map.moveCharacter(_nb, _x, _y, _x, (_y - 1))) {
				_y -= 1;
				return true;
			}
		_direction = Game::Character::Oriented::UP;
	}
	return false;
}

bool Game::Character::moveDown()
{
	if (_hp > 0) {
		if (_direction == Game::Character::Oriented::DOWN)
			if (_map.moveCharacter(_nb, _x, _y, _x, (_y + 1))) {
				_y += 1;
				return true;
			}
		_direction = Game::Character::Oriented::DOWN;
	}
	return false;
}

bool Game::Character::moveRight()
{
	if (_hp > 0) {
		if (_direction == Game::Character::Oriented::RIGHT)
			if (_map.moveCharacter(_nb, _x, _y, (_x + 1), _y)) {
				_x += 1;
				return true;
			}
		_direction = Game::Character::Oriented::RIGHT;
	}
	return false;
}

bool Game::Character::moveLeft()
{
	if (_hp > 0) {
		if (_direction == Game::Character::Oriented::LEFT)
			if (_map.moveCharacter(_nb, _x, _y, (_x - 1), _y)) {
				_x -= 1;
				return true;
			}
		_direction = Game::Character::Oriented::LEFT;
	}
	return false;
}
