#include "TextManager.h"
#include "../Engine.h"
#include "../Localization.h"

#define START_HEIGHT	13

namespace SpaceRaiders
{
	void TextManager::Init( short screenWidth, short screenHeight, short wavesShipStart, short energyTimer )
	{
		m_screenWidth = screenWidth - 1;
		m_screenHeight = screenHeight - 1;
		m_WavesShipStart = wavesShipStart;
		m_EnergyTimer = energyTimer;
	}

	void TextManager::Header()
	{
		Engine::Instance().RenderManager().Text( 0, 0, LOCALE_HEAD );

		Engine::Instance().RenderManager().Text( 0, 1, LOCALE_PIPE ); 
		Engine::Instance().RenderManager().Text( 17, 1, LOCALE_SCORE );
		Engine::Instance().RenderManager().Text( 37, 1, LOCALE_TITLE1 );
		Engine::Instance().RenderManager().Text( 56, 1, LOCALE_HISCORE );
		Engine::Instance().RenderManager().Text( m_screenWidth, 1, LOCALE_PIPE );

		Engine::Instance().RenderManager().Text( 0, 2, LOCALE_PIPE );
		Engine::Instance().RenderManager().Text( 36, 2, LOCALE_TITLE2 );
		Engine::Instance().RenderManager().Text( m_screenWidth, 2, LOCALE_PIPE );

		Engine::Instance().RenderManager().Text( 0, 3, LOCALE_HEAD );
	}

	void TextManager::Footer()
	{
		Engine::Instance().RenderManager().Text( 0, m_screenHeight - 1, LOCALE_PIPE );
		Engine::Instance().RenderManager().Text( m_screenWidth, m_screenHeight - 1, LOCALE_PIPE );
		Engine::Instance().RenderManager().Text( 2, m_screenHeight - 1, LOCALE_ENERGY );
		Engine::Instance().RenderManager().Text( 0, m_screenHeight, LOCALE_FOOT );
	}
	void TextManager::Footer2()
	{
		Engine::Instance().RenderManager().Text( 12, m_screenHeight - 1, LOCALE_EMPTY );
		for( short timer = 0; timer < m_EnergyTimer; timer++ )
		{
			Engine::Instance().RenderManager().Text( 12 + timer, m_screenHeight - 1, LOCALE_TIMER );
		}
	}

	void TextManager::Board()
	{
		for( short x = 0; x <= m_screenWidth; x++ )
		{
			for( short y = m_WavesShipStart; y < m_screenHeight-1; y++ )
			{
				Engine::Instance().RenderManager().Render( x, y, RS_BackgroundTile );
			}
		}
	}

	void TextManager::Energy( short life )
	{
		Engine::Instance().RenderManager().Text( 12 + life, m_screenHeight - 1, LOCALE_BLANK );
	}

	void TextManager::Start()
	{
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 0, LOCALE_MINI );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 1, LOCALE_START1 );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 2, LOCALE_START2 );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 3, LOCALE_MINI );
	}

	void TextManager::Over()
	{
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 0, LOCALE_MINI );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 1, LOCALE_OVER1 );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 2, LOCALE_OVER2 );
		Engine::Instance().RenderManager().Text( 30, START_HEIGHT + 3, LOCALE_MINI );
	}

	void TextManager::Fill()
	{
		for( short x = 30; x <= 50; x++ )
		{
			for( short y = START_HEIGHT; y < START_HEIGHT + 4; y++ )
			{
				Engine::Instance().RenderManager().Render( x, y, RS_BackgroundTile );
			}
		}
	}
}