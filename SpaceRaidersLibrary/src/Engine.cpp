#include "Engine.h"
#include "Constants.h"

namespace SpaceRaiders
{
	void Engine::Init()
	{
		logManager.Init();
		randomManager.Init();

		configManager.Init();
		short gameMode = Engine::Instance().ConfigManager().GetConfig( GAME_MODE );
		short screenWidth = Engine::Instance().ConfigManager().GetConfig( SCREEN_WIDTH );
		short screenHeight = Engine::Instance().ConfigManager().GetConfig( SCREEN_HEIGHT );

		short playerShipHeight = Engine::Instance().ConfigManager().GetConfig( PLAYERSHIP_HEIGHT );
		short playerShipSpeed = Engine::Instance().ConfigManager().GetConfig( PLAYERSHIP_SPEED );
		short playerShipDelay = Engine::Instance().ConfigManager().GetConfig( PLAYERSHIP_DELAY );

		short wavesShipStart = Engine::Instance().ConfigManager().GetConfig( WAVESSHIP_START );
		short alienShipStart = Engine::Instance().ConfigManager().GetConfig( ALIENSHIP_START );
		short alienShipDepth = Engine::Instance().ConfigManager().GetConfig( ALIENSHIP_DEPTH );
		short alienShipSpeed = Engine::Instance().ConfigManager().GetConfig( ALIENSHIP_SPEED );
		
		short playerLaserSpeed = Engine::Instance().ConfigManager().GetConfig( PLAYERLASER_SPEED );
		short alienLaserSpeed = Engine::Instance().ConfigManager().GetConfig( ALIENLASER_SPEED );
		short explosionDelay = Engine::Instance().ConfigManager().GetConfig( EXPLOSION_DELAY );

		short energyTimer = Engine::Instance().ConfigManager().GetConfig( ENERGY_TIMER );
		short startScreen = Engine::Instance().ConfigManager().GetConfig( START_SCREEN );

		gameObjectFactory.Init( screenWidth, screenHeight, playerShipHeight, playerShipSpeed, playerShipDelay, wavesShipStart, alienShipStart, alienShipDepth, alienShipSpeed, playerLaserSpeed, alienLaserSpeed, explosionDelay );
		gameObjectManager.Init( screenWidth, screenHeight, playerShipHeight, playerShipSpeed, playerShipDelay, wavesShipStart, alienShipStart, alienShipDepth, alienShipSpeed, playerLaserSpeed, alienLaserSpeed, explosionDelay );

		inputManager.Init( gameMode );
		textManager.Init( screenWidth, screenHeight, wavesShipStart, energyTimer );

		powerUpManager.Init();
		scoreManager.Init();
		screenManager.Init( startScreen );
	}

	void Engine::Play()
	{
		static float fTickTrigger = 0.0f;
		int iTickCount;

		int fps = configManager.GetConfig( FPS_CONFIG );
		float delta = 1000.0f / fps;

		bool running = true;
		while( running )
		{
			if( inputManager.Escape() )
			{
				running = false;
			}

			iTickCount = frameManager.GetTickCount();
			if( iTickCount > fTickTrigger )
			{
				fTickTrigger = iTickCount + delta;

				screenManager.Update( delta );
				screenManager.Render();
			}
		}
	}

	void Engine::Quit()
	{
		scoreManager.Quit();
		screenManager.Quit();
		gameObjectManager.Quit();
		logManager.Quit();
	}

}