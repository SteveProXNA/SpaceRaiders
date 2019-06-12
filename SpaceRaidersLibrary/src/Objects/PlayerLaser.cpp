#include "PlayerLaser.h"

namespace SpaceRaiders
{
	SpriteAction PlayerLaser::Update( float delta )
	{
		float movementX = m_vel.x * delta / 1000;
		float movementY = m_vel.y * delta / 1000;
		if( 0.0 != movementX || 0.0 != movementY )
		{
			Eraser();

			if( m_pos.x < 0 || m_pos.x >= GetMaxX() || m_pos.y < GetMinY() + 1 )
			{
				return SA_DIE;
			}

			m_pos.x += movementX;
			m_pos.y += movementY;
			Render();
		}

		return SA_NONE;
	}
}