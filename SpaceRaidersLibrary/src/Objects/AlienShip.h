#ifndef _ALIENSHIP_H_
#define _ALIENSHIP_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class AlienShip : public GameObject
	{
	public:
		AlienShip()
		{
			m_objType = OT_AlienShip;
			sprite = RS_Alien;
			state = AS_Normal;
		}
		~AlienShip() {}

		SpriteAction Update( float delta ) override;

		bool DecreaseHealth()
		{
			health -= 1.f; 
			return health <= 0;
		}
		AlienState GetAlienState() const { return state; }

	private:
		AlienState state;
		float health = 1.f;
		float energy = 0.f;
		float direction = 1.f;
	};

}

#endif//_ALIENSHIP_H_