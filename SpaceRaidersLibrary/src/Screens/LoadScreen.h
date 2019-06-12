#ifndef _LOAD_SCREEN_H_
#define _LOAD_SCREEN_H_

#include "BaseScreen.h"
//#include "../Constants.h"

namespace SpaceRaiders
{
	class LoadScreen : public BaseScreen
	{
	public:
		void Init() override;
		ScreenType Update( float delta ) override;
		void Render() override;
	};
}

#endif//_LOAD_SCREEN_H_