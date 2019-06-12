#ifndef _BASE_SCREEN_H_
#define _BASE_SCREEN_H_

#include "../Constants.h"

namespace SpaceRaiders
{
	class BaseScreen
	{
	public:
		BaseScreen() {}
		virtual ~BaseScreen() {}

		virtual void Init() = 0;
		virtual ScreenType Update( float delta ) = 0;
		virtual void Render() = 0;

	protected:
		float timer = 0;
	};
}

#endif//_BASE_SCREEN_H_