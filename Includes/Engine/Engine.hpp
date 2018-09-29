/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
#include "Engine/EventReceiver.hpp"

/** The Engine class keep all basic object needed by the graphical library */
namespace Engine {
	class Engine {
	private:
		/** Use instance() instead */
		Engine(void);
	public:
		~Engine(void);
	public:	/* methods */
		/* to initialize the class: */
		static Engine 			*instance(void);

		/* Useful ? */
		void	 			drop(void);
		EventReceiver 			*getEventReceiver(void);
		irr::IrrlichtDevice 		*getDevice(void) const;
		irr::scene::ISceneManager 	*getSceneManager(void) const;
		irr::video::IVideoDriver 	*getDriver(void) const;
		bool 				keepLooping(void);
		/* @Return true in case of error */
		bool saveGame(const std::vector<std::string> &map, std::string name = "");

	public:
		static constexpr irr::u32 		DIM_VERTICAL = 1080;
		static constexpr irr::u32		DIM_HORIZONTAL = 1920;
	private:
		static Engine				*_instance;
		static constexpr irr::video::E_DRIVER_TYPE VIDEO_TYPE
		= irr::video::EDT_OPENGL;
		static constexpr char	SAVEDGAMES_DIR[] = "SavedGames/";
		irr::IrrlichtDevice			*_device;
		EventReceiver				_EventReceiver;
		irr::video::IVideoDriver		*_driver;
		irr::scene::ISceneManager		*_sceneManager;
	};
}

#endif /* !ENGINE_HPP */
