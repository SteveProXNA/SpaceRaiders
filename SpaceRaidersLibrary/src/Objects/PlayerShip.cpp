#include "PlayerShip.h"
#include "../Engine.h"

namespace SpaceRaiders
{
	SpriteAction PlayerShip::Update( float delta )
	{
		int direction = 0;

		bool left = Engine::Instance().InputManager().Left();
		if( left )
		{
			direction = -1;
		}

		bool right = Engine::Instance().InputManager().Right();
		if( right )
		{
			direction = 1;
		}

		if( 0 != direction )
		{
			Eraser();

			float movement = direction * m_vel.x * delta / 1000;
			SetPosX( m_pos.x + movement );
			if( m_pos.x <= 0 )
			{
				m_pos.x = 0;
			}
			if( m_pos.x >= GetMaxX() )
			{
				m_pos.x = GetMaxX();
			}

			SetPosX( m_pos.x );
			Render();
		}

		if( isShooting )
		{
			timer += delta;
			if( timer >= m_delay )
			{
				timer = 0;
				isShooting = false;
			}
		}
		if( !isShooting )
		{
			bool fire = Engine::Instance().InputManager().Space();
			if( fire )
			{
				short playerLaserCount = Engine::Instance().GameObjectManager().GetPlayerLaserCount();
				if( playerLaserCount > 0 )
				{
					isShooting = true;
					return SA_ADD;
				}
			}
		}

		return SA_NONE;
	}

	void PlayerShip::SwitchLaser()
	{
		laserType = LT_Single == laserType ? LT_Triple : LT_Single;
	}

}