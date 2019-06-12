#ifndef _ALIENLASER_H_
#define _ALIENLASER_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class AlienLaser : public GameObject
	{
	public:
		AlienLaser()
		{
			m_objType = OT_AlienLaser;
			sprite = RS_AlienLaser;
		}
		~AlienLaser() {}

		SpriteAction Update( float delta ) override;
	};

}

#endif//_ALIENLASER_H_