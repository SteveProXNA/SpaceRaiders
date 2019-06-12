#include "ScoreManager.h"
#include "../Constants.h"
#include "../Engine.h"
#include <fstream>

#define MAX_SCORE	65000
#define DATA_ROOT	48		// ASCII code '0'
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	5		// 5 placeholder
#define ALIEN_NORMAL	10
#define ALIEN_BETTER	20

namespace SpaceRaiders
{
	void ScoreManager::Init()
	{
		m_score = 0;
		high = 0;

		std::ifstream myfile;
		myfile.open( SCORE_FILENAME, std::ifstream::in );

		if( myfile.fail() )
		{
			myfile.clear( std::ios::failbit );
			return;
		}

		char buffer[256];
		while( !myfile.eof() )
		{
			myfile.getline( buffer, 100 );
			high = atoi( buffer );
		}

		myfile.close();
	}

	void ScoreManager::Reset()
	{
		m_score = 0;
	}

	void ScoreManager::Update( AlienState state )
	{
		if( AS_Normal == state )
		{
			Update( ALIEN_NORMAL );
		}
		else
		{
			Update( ALIEN_BETTER );
		}
	}

	void ScoreManager::Update( unsigned short score )
	{
		m_score += score;
		if( m_score > MAX_SCORE )
		{
			m_score = MAX_SCORE;
		}
		RenderScore();

		if( m_score > high )
		{
			high = m_score;
			RenderHiScore();
		}
	}

	void ScoreManager::Render()
	{
		RenderScore();
		RenderHiScore();
	}

	void ScoreManager::Quit()
	{
		std::ofstream myfile;
		myfile.open( SCORE_FILENAME, std::ofstream::out );

		if( myfile.fail() )
		{
			myfile.clear( std::ios::failbit );
			return;
		}

		myfile << high;
		myfile.close();
	}

	void ScoreManager::Render( unsigned short data, unsigned short x, unsigned short y )
	{
		unsigned char idx;
		signed char tile;

		unsigned int quotient = 0;
		unsigned char remainder = 0;

		char hold[DATA_LONG];
		for( idx = 0; idx < DATA_LONG; ++idx )
		{
			hold[idx] = data % UNIT_ROOT;
			data /= UNIT_ROOT;

			tile = hold[idx] + DATA_ROOT;
			Engine::Instance().RenderManager().Render( x, y, tile );
			x--;
		}
	}
	void ScoreManager::RenderScore()
	{
		// Remove hard coded values
		Render( m_score, 21, 2 );
	}
	void ScoreManager::RenderHiScore()
	{
		// Remove hard coded values
		Render( high, 63, 2 );
	}

}