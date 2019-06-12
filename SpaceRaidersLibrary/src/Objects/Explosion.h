#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class Explosion : public GameObject
	{
	public:
		Explosion()
		{
			m_objType = OT_Explosion;
			sprite = RS_Explosion;
			timer = 0;
		}
		~Explosion() {}

		SpriteAction Update( float delta ) override;

		inline void SetDelay( float delay ) { m_delay = delay; }

	private:
		float m_delay;
		float timer;
	};

}

#endif//_EXPLOSION_H_