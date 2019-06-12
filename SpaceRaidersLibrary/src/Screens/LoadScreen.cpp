#include "LoadScreen.h"
#include "../Engine.h"
#include "../Objects/PlayerShip.h"
#include "../Objects/AlienShip.h"

namespace SpaceRaiders
{
	void LoadScreen::Init()
	{
		Engine::Instance().TextManager().Footer();
		Engine::Instance().TextManager().Footer2();
		Engine::Instance().TextManager().Header();
		Engine::Instance().TextManager().Board();
		Engine::Instance().TextManager().Start();

		Engine::Instance().ScoreManager().Reset();
		Engine::Instance().ScoreManager().Render();

		Engine::Instance().GameObjectManager().CreateAll();
		Engine::Instance().GameObjectManager().Render();
		Engine::Instance().GameObjectManager().RenderBarriers();
		Engine::Instance().PowerUpManager().Hide();
		Engine::Instance().RenderManager().Empty();
	}

	ScreenType LoadScreen::Update( float delta )
	{
		bool enter = Engine::Instance().InputManager().Return();
		if( enter )
		{
			Engine::Instance().TextManager().Fill();
			return PLAY_SCREEN;
		}

		return LOAD_SCREEN;
	}

	void LoadScreen::Render()
	{
		Engine::Instance().GameObjectManager().Render();
		Engine::Instance().RenderManager().Empty();
	}

}