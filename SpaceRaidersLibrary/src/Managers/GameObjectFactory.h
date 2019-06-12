#ifndef _GAMEOBJECT_FACTORY_H_
#define _GAMEOBJECT_FACTORY_H_

#include "../Objects/AlienLaser.h"
#include "../Objects/AlienShip.h"
#include "../Objects/Barrier.h"
#include "../Objects/Explosion.h"
#include "../Objects/PlayerShip.h"
#include "../Objects/PlayerLaser.h"
#include "../Objects/PowerUp.h"
#include "../Constants.h"
#include "../Vector2D.h"

namespace SpaceRaiders
{
	class GameObjectFactory
	{
	public:
		GameObjectFactory() {}
		~GameObjectFactory() {}

		void Init( short screenWidth, short screenHeight, short playerShipHeight, short playerShipSpeed, short playerShipDelay, short wavesShipStart, short alienShipStart, short alienShipDepth, short alienShipSpeed, short playerLaserSpeed, short alienLaserSpeed, short explosionDelay );

		PlayerShip* CreatePlayerShip();
		AlienShip* CreateAlienShip( float posX, float posY );
		PlayerLaser* CreatePlayerLaserOne( float posX, float posY );
		PlayerLaser* CreatePlayerLaserTwo( float posX, float posY );
		PlayerLaser* CreatePlayerLaserThree( float posX, float posY );
		AlienLaser* CreateAlienLaser( float posX, float posY );
		Barrier* CreateBarrier( float posX, float posY );
		Explosion* CreateExplosion( Vector2D pos );
		PowerUp* CreatePowerUp( PowerUpType powerUpType, float posX, float posY );

	private:
		short m_ScreenWidth;
		short m_ScreenHeight;
		short m_PlayerShipHeight;
		short m_PlayerShipSpeed;
		short m_PlayerShipDelay;
		short m_WavesShipStart;
		short m_AlienShipStart;
		short m_AlienShipDepth;
		short m_AlienShipSpeed;
		short m_PlayerLaserSpeed;
		short m_AlienLaserSpeed;
		short m_ExplosionDelay;
	};
}

#endif//_GAMEOBJECT_FACTORY_H_