#include "ScreenManager.h"

namespace SpaceRaiders
{
	void ScreenManager::Init( short startScreen )
	{
		screens[LOAD_SCREEN] = new LoadScreen();
		screens[PLAY_SCREEN] = new PlayScreen();
		screens[OVER_SCREEN] = new OverScreen();

		currScreen = static_cast<ScreenType>(startScreen);
		nextScreen = currScreen;

		screens[currScreen]->Init();
	}

	void ScreenManager::Quit()
	{
		for( char index = 0; index < MAX_SCREENS; ++index )
		{
			BaseScreen* screen = screens[index];
			if( nullptr != screen )
			{
				delete screen;
				screen = nullptr;
			}
		}
	}

	void ScreenManager::Update( float delta )
	{
		if( currScreen != nextScreen )
		{
			currScreen = nextScreen;
			screens[currScreen]->Init();
		}

		nextScreen = screens[currScreen]->Update( delta );
	}

	void ScreenManager::Render()
	{
		screens[currScreen]->Render();
	}

}