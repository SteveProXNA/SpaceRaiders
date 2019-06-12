#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

#include "BaseScreen.h"
//#include "../Constants.h"

namespace SpaceRaiders
{
	class PlayScreen : public BaseScreen
	{
	public:
		void Init() override;
			ScreenType Update( float delta ) override;
			void Render() override;

	private:
		float delay;
		short life;
	};
}

#endif//_PLAY_SCREEN_H_