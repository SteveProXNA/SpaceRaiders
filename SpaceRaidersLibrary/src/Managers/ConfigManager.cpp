#include "ConfigManager.h"
#include "../Constants.h"
#include "../Engine.h"
#include <fstream>

namespace SpaceRaiders
{
	void ConfigManager::Init()
	{
		memset( m_iConfig, 0, sizeof( m_iConfig ) );

		// Default values.
		m_iConfig[GAME_MODE] = 1;
		m_iConfig[FPS_CONFIG] = 50;
		m_iConfig[SCREEN_WIDTH] = 80;
		m_iConfig[SCREEN_HEIGHT] = 28;
		m_iConfig[PLAYERSHIP_HEIGHT] = 25;
		m_iConfig[PLAYERSHIP_SPEED] = 16;
		m_iConfig[PLAYERSHIP_DELAY] = 100;
		m_iConfig[WAVESSHIP_START] = 4;
		m_iConfig[WAVESSHIP_SIZE] = 5;
		m_iConfig[ALIENSHIP_COUNT] = 20;
		m_iConfig[ALIENSHIP_START] = 8;
		m_iConfig[ALIENSHIP_DEPTH] = 4;
		m_iConfig[ALIENSHIP_SPEED] = 12;
		m_iConfig[PLAYERLASER_COUNT] = 4;
		m_iConfig[PLAYERLASER_SPEED] = 10;
		m_iConfig[ALIENLASER_COUNT] = 10;
		m_iConfig[ALIENLASER_SPEED] = 10;
		m_iConfig[EXPLOSION_DELAY] = 900;
		m_iConfig[ENERGY_TIMER] = 60;
		m_iConfig[START_SCREEN] = 0;

		// Config values.
		std::ifstream myfile;
		myfile.open( CONFIG_FILENAME, std::ifstream::in );

		if( myfile.fail() )
		{
			myfile.clear( std::ios::failbit );
			LogConfiguration();
			return;
		}

		// Load configuration.
		char buffer[256];
		char cnt = 0;

		while( !myfile.eof() )
		{
			myfile.getline( buffer, 100 );
			m_iConfig[cnt++] = atoi( buffer );
		}

		myfile.close();
		LogConfiguration();
	}

	void ConfigManager::LogConfiguration()
	{
		// Log all configuration!
	}

}