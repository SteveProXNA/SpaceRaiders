#include "AlienShip.h"
#include "../Engine.h"

namespace SpaceRaiders
{
	const float maxUpdateRate = 0.01f;
	const float transformEnergy = 1.f;

	SpriteAction AlienShip::Update( float delta )
	{
		// Border check
		float movement = direction * m_vel.x * delta / 1000;
		if( 0.0 != movement )
		{
			Eraser();

			m_pos.x += movement;
			if( m_pos.x <= 0 || m_pos.x > GetMaxX() )
			{
				direction = -direction;
				m_pos.y += 1;
			}

			Render();
		}

		// Transform into better Alien
		if( 0.0 != movement )
		{
			if( state != AS_Better )
			{
				float updateRate = Engine::Instance().RandomManager().Next( -maxUpdateRate, 2 * maxUpdateRate );
				energy += updateRate;
				if( energy >= transformEnergy )
				{
					health = 2.f;
					state = AS_Better;
					sprite = RS_BetterAlien;
					m_vel.x *= 2.f;
					Render();
				}
			}
		}

		// Can't spawn laser near bottom
		if( GetMaxY() - (int)m_pos.y >= 2 )
		{
			short alienLaserCount = Engine::Instance().GameObjectManager().GetAlienLaserCount();
			if( alienLaserCount > 0 )
			{
				float fireRate = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
				if( fireRate < 0.5f )
				{
					return SA_ADD;
				}
			}
		}

		return SA_NONE;
	}
}