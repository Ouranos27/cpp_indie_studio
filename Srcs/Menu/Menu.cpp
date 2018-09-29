/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Menu
** File description:
**      Created by Amaury Bernard, the 6/10/18, at 2:17 PM
*/

#include <Game/Game.hpp>
#include "Menu/Menu.hpp"

Menu::Menu::Menu(void)
{
	this->createButtons();
	_engine->getDriver()->beginScene(true, true,
	irr::video::SColor(0, 0, 0, 0));
	irr::video::ITexture* images =
	_engine->getDriver()->getTexture("./textures/background.jpg");
	_engine->getDriver()->draw2DImage(images,
	irr::core::position2d<irr::s32>(0,0),
	irr::core::rect<irr::s32>(0,0, Engine::Engine::DIM_HORIZONTAL,
	Engine::Engine::DIM_HORIZONTAL), 0,
	irr::video::SColor(255,255,255,255), true);
	_engine->getSceneManager()->drawAll();
	_guiEnv->drawAll();
	_engine->getDriver()->endScene();
}

/* Order have to correspond with btnEnm until it was replace by a map*/
void Menu::Menu::createButtons()
{
	createMenuButton("Play at 2");
	createMenuButton("PLAY with IA");
	createMenuButton("Play on LAN");
	createMenuButton("Play from Backup");
	createMenuButton("Exit");
	createRightButton("Low Level");
	createRightButton("Medium Level");
	createRightButton("Hard Level");
}

Game::Game *Menu::Menu::getSelectedGame(void)
{
	ButtonId btn = (ButtonId)_engine->getEventReceiver()->getBtnId();
	switch (btn)
	{
	case ButtonId::PLAY_KB:
		return new Game::Game(2, _GameSize, DENSITY_MEDIUM);
	case ButtonId::PLAY_IA:
		return new Game::Game(1, _GameSize, DENSITY_MEDIUM);
		break;
	case ButtonId::PLAY_LAN:
		return new Game::Game(1, _GameSize, DENSITY_MEDIUM);
		break;
	case ButtonId::BACKUP:
		//Change the screen and show an other menu
		return new Game::Game(1, _GameSize, DENSITY_MEDIUM);
		break;
	case ButtonId::EXIT:
		_engine->getDevice()->closeDevice();
		return nullptr;
	case ButtonId::EXIT + 1:
		_GameSize = SMALL;
		return nullptr;
	case ButtonId::EXIT + 2:
		_GameSize = MEDIUM;
		return nullptr;
	case ButtonId::EXIT + 3:
		_GameSize = BIG;
		return nullptr;
	}
	return nullptr;
}

void Menu::Menu::createMenuButton(const std::string &name, irr::core::stringw to_show)
{
	if (to_show.empty()) {
		to_show = name.c_str();
	}
	irr::s32 vert = 100;
	_guiEnv->addButton(irr::core::rect<irr::s32>(
		Engine::Engine::DIM_HORIZONTAL/2 - 300,
		vert - 50 + (150 * _btnSize),
		Engine::Engine::DIM_HORIZONTAL/2 + 300,
		vert + 50 + (150 * _btnSize)), 0,
	++_btnSize, to_show.c_str(), to_show.c_str());
}

void Menu::Menu::createRightButton(const std::string &name, irr::core::stringw to_show)
{
	if (to_show.empty()) {
		to_show = name.c_str();
	}
	irr::s32 vert = Engine::Engine::DIM_VERTICAL - 800;
	irr::s32 horiz = Engine::Engine::DIM_HORIZONTAL - 250;
	_guiEnv->addButton(irr::core::rect<irr::s32>(
		horiz,
		vert + (75 * _btnSize),
		horiz + 120,
		vert + 50 + (75 * _btnSize)), 0,
		++_btnSize, to_show.c_str(), to_show.c_str());
	++_btnRightSize;
}

