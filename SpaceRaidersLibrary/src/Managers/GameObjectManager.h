#ifndef _GAMEOBJECT_MANAGER_H_
#define _GAMEOBJECT_MANAGER_H_

#include "../Objects/GameObject.h"
#include "../Objects/PlayerShip.h"
#include <algorithm>
#include <vector>

namespace SpaceRaiders
{
	typedef GameObject* GameObjPtr;

	class GameObjectManager
	{
	public:
		GameObjectManager() {}
		~GameObjectManager() {}

		void Init( short screenWidth, short screenHeight, short playerShipHeight, short playerShipSpeed, short playerShipDelay, short wavesShipStart, short alienShipStart, short alienShipDepth, short alienShipSpeed, short playerLaserSpeed, short alienLaserSpeed, short explosionDelay );

		void CreateAll();
		void CreatePlayerShip();
		void CreateAlienShips();
		void CreateAlienWaves();
		void CreateBarriers();

		void UpdateShips( float delta );
		void UpdateLasers( float delta );
		void UpdateExplosions( float delta );
		void UpdatePowerUp( float delta );
		void FinishPowerUp( float delta );
		void ActionPowerUp();

		void CollidePlayerShip();
		bool CollideAlienShips();
		bool CollideAlienLasers();
		void CollidePlayerLasers();

		void Render();
		void RenderBarriers();

		void AddPlayerShip( PlayerShip* playerShip );
		void AddAlienShip( GameObject* newObj );
		void AddPlayerLaser( GameObject* newObj );
		void AddAlienLaser( GameObject* newObj );
		void AddExplosion( GameObject* newObj );
		void AddBarrier( GameObject* newObj );
		void AddPowerUp( GameObject* newObj );

		void RemoveAlienShip( GameObject* newObj );
		void RemovePlayerLaser( GameObject* newObj );
		void RemoveAlienLaser( GameObject* newObj );
		void RemoveExplosion( GameObject* newObj );
		void RemoveBarrier( GameObject* newObj );
		void RemovePowerUp( GameObject* newObj );

		void RemoveAll();
		void RemovePlayerShip();
		void RemoveAlienShips();
		void RemovePlayerLasers();
		void RemoveAlienLasers();
		void RemoveBarriers();
		void RemoveExplosions();
		void RemovePowerUps();
		void Quit();

		const std::vector<GameObjPtr>& GetAlienShips() { return alienShips; }
		PlayerShip* GetPlayerShip() const { return m_playerShip; }

		inline short GetPlayerLaserCount() const { return m_PlayerLaserCount; }
		inline void IncPlayerLaserCount() { m_PlayerLaserCount++; }
		inline void DecPlayerLaserCount() { m_PlayerLaserCount--; }
		//inline void SetPlayerLaserCount( short count ) { m_PlayerLaserCount = count; }
		
		inline short GetAlienLaserCount() const { return m_AlienLaserCount; }
		inline void IncAlienLaserCount() { m_AlienLaserCount++; }
		inline void DecAlienLaserCount() { m_AlienLaserCount--; }
		//inline void SetAlienLaserCount( short count ) { m_AlienLaserCount = count; }

		inline short GetPowerUpCount() const { return m_PowerUpCount; }
		inline void IncPowerUpCount() { m_PowerUpCount++; }
		inline void DecPowerUpCount() { m_PowerUpCount--; }

	private:
		void RemoveAllFromCollection( std::vector<GameObjPtr>& collection );
		void RemoveObjectFromCollection( std::vector<GameObjPtr>& collection, GameObject* newOb );

		std::vector<GameObjPtr> alienShips;
		std::vector<GameObjPtr> playerLasers;
		std::vector<GameObjPtr> alienLasers;
		std::vector<GameObjPtr> barriers;
		std::vector<GameObjPtr> explosions;
		std::vector<GameObjPtr> powerUps;
		PlayerShip* m_playerShip = nullptr;

		short m_PlayerLaserCount = 0;
		short m_AlienLaserCount = 0;
		short m_PowerUpCount = 0;
		PowerUpType m_PowerUpGet = PU_NONE;
		PowerUpType m_PowerUpUse = PU_NONE;

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

#endif//_GAMEOBJECT_MANAGER_H_