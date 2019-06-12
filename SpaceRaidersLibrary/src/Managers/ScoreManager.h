#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#include "../Constants.h"

namespace SpaceRaiders
{
	class ScoreManager
	{
	public:
		ScoreManager() 
		{
			m_score = 0;
			high= 0;
		}

		~ScoreManager() {}

		void Init();
		void Reset();
		void Update( AlienState state );
		void Update( unsigned short score );
		void Render();
		void Quit();

	private:
		void Render( unsigned short data, unsigned short x, unsigned short y );
		void RenderScore();
		void RenderHiScore();
		unsigned short m_score;
		unsigned short high;
	};
}

#endif//_SCORE_MANAGER_H_