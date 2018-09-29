/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, EventReceiver
** File description:
**      Created by Amaury Bernard, the 5/31/18, at 3:18 PM
*/

#ifndef EVENTRECEIVER_HPP
#define EVENTRECEIVER_HPP
#include <irrlicht/irrlicht.h>
#include <vector>
#include "Menu/BtnEnum.hpp"

namespace Engine {
	class EventReceiver : public irr::IEventReceiver {
	/* Public things */
	public:
		EventReceiver(irr::IrrlichtDevice &device);
	public: /* Methods */
		virtual bool 	OnEvent(const irr::SEvent& event);
		bool 		isKeyDown(irr::EKEY_CODE keyCode);
		/** Have to be executed at each frame
		** todo check is this is nececsary
		*/
		void 		update(void);
	/* Private things */
	private: /* Methods */
		void		resetKeysDown(void);
	private: /* variables */
		irr::IrrlichtDevice 	&_device;
		Menu::ButtonId 		_btnId = Menu::ButtonId::NONE;
	public:
		Menu::ButtonId getBtnId() const;
	private:
		/** @var _KeysDown
		** @copydoc http://irrlicht.sourceforge.net/docu/namespaceirr.html#a54da2a0e231901735e3da1b0edf72eb3
		*/
		bool 			_keysDown[irr::KEY_KEY_CODES_COUNT];
	};
}

#endif /* !EVENTRECEIVER_HPP*/
