#include "PowerUp.h"

namespace SpaceRaiders
{
	SpriteAction PowerUp::Update( float delta )
	{
		float movementY = m_vel.y * delta / 1000;
		if( 0.0 != movementY )
		{
			Eraser();
			if( m_pos.y >= GetMaxY() )
			{
				return SA_DIE;
			}

			m_pos.y += movementY;
			Render();
		}

		return SA_NONE;
	}

}