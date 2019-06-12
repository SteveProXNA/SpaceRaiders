#include "OverScreen.h"
#include "../Engine.h"

#define GAMEOVER_DELAY	8000

namespace SpaceRaiders
{
	void OverScreen::Init()
	{
		Engine::Instance().TextManager().Footer();
		Engine::Instance().TextManager().Header();

		Engine::Instance().GameObjectManager().Render();
		Engine::Instance().TextManager().Over();

		Engine::Instance().ScoreManager().Render();
		timer = 0;
	}

	ScreenType OverScreen::Update( float delta )
	{
		timer += delta;

		bool over = timer > GAMEOVER_DELAY;
		bool exit = Engine::Instance().InputManager().Exit();

		if( over || exit )
		{
			Engine::Instance().GameObjectManager().RemoveAll();
			Engine::Instance().TextManager().Fill();
			return LOAD_SCREEN;
		}

		return OVER_SCREEN;
	}

	void OverScreen::Render()
	{
		Engine::Instance().RenderManager().Empty();
	}

}