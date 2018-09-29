/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <vector>
#include <iostream>
#include <ctime>
#include "FileSystem/File.hpp"
#include "FileSystem/Directory.hpp"
#include "Engine/Engine.hpp"

Engine::Engine *Engine::Engine::_instance;

Engine::Engine::Engine(void)
: _device(irr::createDevice(VIDEO_TYPE,
irr::core::dimension2d<irr::u32>(DIM_HORIZONTAL, DIM_VERTICAL))),
_EventReceiver(EventReceiver(*_device))
{
	if (!_device) {
		std::cerr << "Engine::Engine(): createDevice" << std::endl;
		throw std::exception();
	}
	_driver = _device->getVideoDriver();
	if (!_driver) {
		std::cerr << "Engine::Engine(): VideoDriver" << std::endl ;
		throw std::exception();
	}
	_sceneManager = _device->getSceneManager();
	if (!_sceneManager) {
		std::cerr << "Engine::Engine(): SceneManager" << std::endl ;
		throw std::exception();
	}
	_device->setEventReceiver(&_EventReceiver);
}

Engine::Engine::~Engine(void)
{
	_device->drop();
}

irr::IrrlichtDevice *Engine::Engine::getDevice() const
{
	return _device;
}

irr::video::IVideoDriver *Engine::Engine::getDriver() const
{
	return _driver;
}

irr::scene::ISceneManager *Engine::Engine::getSceneManager() const
{
	return _sceneManager;
}

Engine::EventReceiver *Engine::Engine::getEventReceiver()
{
	return &_EventReceiver;
}


Engine::Engine *Engine::Engine::instance(void)
{
	if (!_instance)
		_instance = new Engine;
	return (_instance);
}

void Engine::Engine::drop(void)
{
	delete(_instance);
}

bool Engine::Engine::saveGame(const std::vector<std::string> &map, std::string name)
{
	if (name.empty())
		name = std::to_string(std::time(nullptr));
	FileSystem::Directory dir((char *)Engine::Engine::SAVEDGAMES_DIR);
	if (!dir.exist()) {
		dir.create();
	}
	FileSystem::File file(dir.getAbsolutePath() + name);
	file.write(std::to_string(map.size()) + std::string("\n"));
	for (auto line : map) {
		file.write(line + std::string("\n"));
	}
	return false;
}

bool Engine::Engine::keepLooping(void)
{
	this->getEventReceiver()->update();
	return this->getDevice()->run() && this->getDriver();
}
