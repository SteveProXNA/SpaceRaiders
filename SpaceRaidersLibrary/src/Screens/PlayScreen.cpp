#include "PlayScreen.h"
#include "../Constants.h"
#include "../Engine.h"

namespace SpaceRaiders
{
	void PlayScreen::Init()
	{
		Engine::Instance().TextManager().Footer();
		Engine::Instance().TextManager().Footer2();
		Engine::Instance().TextManager().Header();
		Engine::Instance().ScoreManager().Render();

		short startScreen = Engine::Instance().ConfigManager().GetConfig( START_SCREEN );
		ScreenType currScreen = static_cast<ScreenType>(startScreen);
		if( PLAY_SCREEN == currScreen )
		{
			Engine::Instance().TextManager().Board();
			Engine::Instance().GameObjectManager().CreateAll();
			Engine::Instance().GameObjectManager().Render();
			Engine::Instance().GameObjectManager().RenderBarriers();
			Engine::Instance().PowerUpManager().Hide();
		}
		
		Engine::Instance().RenderManager().Empty();
		delay = (float)Engine::Instance().ConfigManager().GetConfig( ENERGY_TIMER );
		life = (short)delay;
		delay *= 1000;
		timer = 0;
	}

	ScreenType PlayScreen::Update( float delta )
	{
		bool quit = Engine::Instance().InputManager().Quit();
		if( quit )
		{
			return OVER_SCREEN;
		}

		timer += delta;
		if( 0 == (int)timer % 1000 )
		{
			life--;
			Engine::Instance().TextManager().Energy( life );
		}

		if( timer > delay )
		{
			return OVER_SCREEN;
		}

		Engine::Instance().GameObjectManager().UpdateShips( delta );
		Engine::Instance().GameObjectManager().UpdateLasers( delta );

		bool gameOver = Engine::Instance().GameObjectManager().CollideAlienShips();
		if( gameOver )
		{
			return OVER_SCREEN;
		}
		gameOver = Engine::Instance().GameObjectManager().CollideAlienLasers();
		if( gameOver )
		{
			return OVER_SCREEN;
		}

		Engine::Instance().GameObjectManager().CollidePlayerShip();
		Engine::Instance().GameObjectManager().CollidePlayerLasers();
		Engine::Instance().GameObjectManager().UpdateExplosions( delta );
		Engine::Instance().GameObjectManager().UpdatePowerUp( delta );
		Engine::Instance().GameObjectManager().FinishPowerUp( delta );

		return PLAY_SCREEN;
	}

	void PlayScreen::Render()
	{
		Engine::Instance().GameObjectManager().Render();
		Engine::Instance().RenderManager().Empty();
	}

}