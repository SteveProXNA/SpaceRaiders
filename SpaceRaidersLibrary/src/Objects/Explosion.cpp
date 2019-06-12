#include "Explosion.h"

namespace SpaceRaiders
{
	SpriteAction Explosion::Update( float delta )
	{
		timer += delta;
		if( timer > m_delay )
		{
			timer = 0;
			return SA_DIE;
		}

		return SA_NONE;
	}
}