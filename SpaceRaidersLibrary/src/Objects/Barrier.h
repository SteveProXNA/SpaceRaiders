#ifndef _BARRIER_H_
#define _BARRIER_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class Barrier : public GameObject
	{
	public:
		Barrier()
		{
			m_objType = OT_Barrier;
			sprite = RS_Barrier;
		}
		~Barrier() {}

		SpriteAction Update( float delta ) override;
	};

}

#endif//_ALIENSHIP_H_