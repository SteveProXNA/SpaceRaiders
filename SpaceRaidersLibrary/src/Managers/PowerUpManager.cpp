#include "PowerUpManager.h"
#include "../Engine.h"
#include "../Localization.h"

#define POWERUP_DELAY	5000

namespace SpaceRaiders
{
	void PowerUpManager::Init()
	{
		Reset();
	}

	void PowerUpManager::Reset()
	{
		timer = 0;
	}

	bool PowerUpManager::Update( float delta )
	{
		bool finished = false;

		timer += delta;
		if( timer > POWERUP_DELAY )
		{
			Hide();
			Reset();
			finished = true;
		}

		return finished;
	}

	void PowerUpManager::Show()
	{
		Engine::Instance().RenderManager().Text( 74, 26, LOCALE_POWER );
	}

	void PowerUpManager::Hide()
	{
		Engine::Instance().RenderManager().Text( 74, 26, LOCALE_BLANK );
	}
}