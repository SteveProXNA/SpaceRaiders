#ifndef _SCREEN_MANAGER_H_
#define _SCREEN_MANAGER_H_

#include "../Screens/BaseScreen.h"
#include "../Screens/LoadScreen.h"
#include "../Screens/PlayScreen.h"
#include "../Screens/OverScreen.h"
#include "../Constants.h"

namespace SpaceRaiders
{
	class ScreenManager
	{
	public:
		ScreenManager() {}
		~ScreenManager() {}

		void Init( short startScreen );
		void Quit();

		void Update( float delta );
		void Render();

	private:
		BaseScreen* screens[MAX_SCREENS];
		LoadScreen* loadScreen;
		PlayScreen* playScreen;
		OverScreen* overScreen;

		ScreenType currScreen;
		ScreenType nextScreen;
	};
}

#endif//_SCREEN_MANAGER_H_