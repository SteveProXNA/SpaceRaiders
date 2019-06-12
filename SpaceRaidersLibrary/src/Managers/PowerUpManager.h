#ifndef _POWERUP_MANAGER_H_
#define _POWERUP_MANAGER_H_

#include "../Constants.h"

namespace SpaceRaiders
{
	class PowerUpManager
	{
	public:
		PowerUpManager() {}
		~PowerUpManager() {}

		void Init();
		void Reset();
		bool Update( float delta );

		void Show();
		void Hide();

	private:
		float timer;
	};
}

#endif//_POWERUP_MANAGER_H_