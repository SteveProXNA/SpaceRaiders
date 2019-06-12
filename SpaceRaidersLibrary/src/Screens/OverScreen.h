#ifndef _OVER_SCREEN_H_
#define _OVER_SCREEN_H_

#include "BaseScreen.h"
//#include "../Constants.h"

namespace SpaceRaiders
{
	class OverScreen : public BaseScreen
	{
	public:
		void Init() override;
		ScreenType Update( float delta ) override;
		void Render() override;
	};
}

#endif//_OVER_SCREEN_H_