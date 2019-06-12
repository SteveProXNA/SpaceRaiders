#include "GameObjectManager.h"
#include "../Engine.h"
#include "../Objects/PlayerLaser.h"
#include "../Objects/Explosion.h"

namespace SpaceRaiders
{
	void GameObjectManager::UpdateShips( float delta )
	{
		// Update list of active objects in the world
		SpriteAction playerShipAction = m_playerShip->Update( delta );
		if( playerShipAction & SA_ADD )
		{
			float x = m_playerShip->GetPosX();
			float y = m_playerShip->GetPosY();
			PlayerLaser* pl = Engine::Instance().GameObjectFactory().CreatePlayerLaserOne( x, y );
			AddPlayerLaser( pl );
			pl->Render();

			// Determine if power up player laser
			LaserType laserType = m_playerShip->GetLaserType();
			if( LT_Triple == laserType )
			{
				PlayerLaser* pl2 = Engine::Instance().GameObjectFactory().CreatePlayerLaserTwo( x, y );
				AddPlayerLaser( pl2 );
				pl2->Render();

				PlayerLaser* pl3 = Engine::Instance().GameObjectFactory().CreatePlayerLaserThree( x, y );
				AddPlayerLaser( pl3 );
				pl3->Render();
			}

			DecPlayerLaserCount();
		}

		// Update alien ships
		for( auto it : alienShips )
		{
			SpriteAction alienShipAction = it->Update( delta );
			if( alienShipAction & SA_ADD )
			{
				AlienLaser* al = Engine::Instance().GameObjectFactory().CreateAlienLaser( it->GetPosX(), it->GetPosY() + 1 );
				AddAlienLaser( al );
				al->Render();
				DecAlienLaserCount();
			}
		}
	}

	void GameObjectManager::UpdateLasers( float delta )
	{
		// Update player lasers
		for( auto it : playerLasers )
		{
			SpriteAction playerLaserAction = it->Update( delta );
			if( playerLaserAction & SA_DIE )
			{
				// Destroy player laser
				(*it).Eraser();
				IncPlayerLaserCount();
				RemovePlayerLaser( it );
				delete it;
				break;
			}
		}	

		// Update alien lasers
		for( auto it : alienLasers )
		{
			SpriteAction alienLaserAction = it->Update( delta );
			if( alienLaserAction & SA_DIE )
			{
				// Destroy alien laser
				(*it).Eraser();
				IncAlienLaserCount();
				RemoveAlienLaser( it );
				delete it;
				break;
			}
		}
	}

	void GameObjectManager::UpdateExplosions( float delta )
	{
		// Update explosions
		for( auto it : explosions )
		{
			SpriteAction explosionAction = it->Update( delta );
			if( explosionAction & SA_DIE )
			{
				// Destroy explosion
				(*it).Eraser();
				RemoveExplosion( it );
				delete it;
				break;
			}
		}
	}

	void GameObjectManager::UpdatePowerUp( float delta )
	{
		// Update power up
 		for( auto it : powerUps )
		{
			SpriteAction powerUpAction = it->Update( delta );
			if( powerUpAction & SA_DIE )
			{
				// Destroy power up
				(*it).Eraser();
				RemovePowerUp( it );
				delete it;
				m_PowerUpGet = PU_NONE;
				m_PowerUpUse = PU_NONE;
				break;
			}
		}
	}

	void GameObjectManager::FinishPowerUp( float delta )
	{
		if( PU_NONE == m_PowerUpUse )
		{
			return;
		}

		bool finished = Engine::Instance().PowerUpManager().Update( delta );
		if( !finished )
		{
			return;
		}

		if( PU_One == m_PowerUpUse )
		{
			Vector2D getVel = m_playerShip->GetVel();
			Vector2D setVel = Vector2D( getVel.x /= 2, getVel.y );
			m_playerShip->SetVel( setVel );
		}
		else if( PU_Two == m_PowerUpUse )
		{
			float delay = m_playerShip->GetDelay();
			m_playerShip->SetDelay( delay * 2 );
		}
		else if( PU_Three == m_PowerUpUse )
		{
			m_playerShip->SwitchLaser();
		}

		Engine::Instance().PowerUpManager().Hide();
		m_PowerUpGet = PU_NONE;
		m_PowerUpUse = PU_NONE;
	}

	void GameObjectManager::ActionPowerUp()
	{
		if( PU_One == m_PowerUpUse )
		{
			Vector2D getVel = m_playerShip->GetVel();
			Vector2D setVel = Vector2D( getVel.x *= 2, getVel.y );
			m_playerShip->SetVel( setVel );
		}
		if( PU_Two == m_PowerUpUse )
		{
			float delay = m_playerShip->GetDelay();
			m_playerShip->SetDelay( delay / 2 );
		}
		if( PU_Three == m_PowerUpUse )
		{
			m_playerShip->SwitchLaser();
		}
	}

	void GameObjectManager::CollidePlayerShip()
	{
		if( PU_NONE == m_PowerUpGet )
		{
			return;
		}

		// Update power up
		for( auto it : powerUps )
		{
			Vector2D pos = (*it).GetPos();

			// Detect alien ship collides with player ship
			if( m_PlayerShipHeight == (int)pos.y )
			{
				Vector2D pos2 = m_playerShip->GetPos();
				bool collide = pos.IntCmp( pos2 );
				if( collide )
				{
					// Destroy power up
					(*it).Eraser();
					RemovePowerUp( it );
					delete it;

					// Action power up
					m_PowerUpUse = m_PowerUpGet;
					m_PowerUpGet = PU_NONE;
					ActionPowerUp();
					Engine::Instance().PowerUpManager().Show();
					break;
				}
			}
		}
	}

	bool GameObjectManager::CollideAlienShips()
	{
		bool death = false;

		// Update alien ships
		for( auto it : alienShips )
		{
			Vector2D pos = (*it).GetPos();

			// Detect alien ship collides with player ship
			if( m_PlayerShipHeight == pos.y )
			{
				Vector2D pos2 = m_playerShip->GetPos();
				bool collide = pos.IntCmp( pos2 );
				if( collide )
				{
					Explosion* ex = Engine::Instance().GameObjectFactory().CreateExplosion( pos );
					AddExplosion( ex );
					ex->Render();
					RemovePlayerShip();
					death = true;
					break;
				}
			}

			// Detect alien ship collides with barrier
			if( 20 == (int)pos.y || 21 == (int)pos.y )
			{
				for( auto it2 : barriers )
				{
					Vector2D pos2 = (*it2).GetPos();
					bool collide = pos.IntCmp( pos2 );
					if( collide )
					{
						// Destroy barrier
						(*it2).Eraser();
						RemoveBarrier( it2 );
						delete it2;
						break;
					}
				}
			}

		}

		if( death )
		{
			return true;
		}

		return false;
	}

	bool GameObjectManager::CollideAlienLasers()
	{
		bool death = false;

		// Update alien lasers
		for( auto it : alienLasers )
		{
			Vector2D pos = (*it).GetPos();

			// Detect alien laser collides with player ship
			Vector2D pos2 = m_playerShip->GetPos();
			bool collide = pos.IntCmp( pos2 );
			if( collide )
			{
				Explosion* ex = Engine::Instance().GameObjectFactory().CreateExplosion( pos );
				AddExplosion( ex );
				ex->Render();
				RemovePlayerShip();
				death = true;
				break;
			}

			// Detect alien laser collides with barrier
			if( 20 == (int)pos.y || 21 == (int)pos.y )
			{
				for( auto it2 : barriers )
				{
					Vector2D pos2 = (*it2).GetPos();
					bool collide = pos.IntCmp( pos2 );
					if( collide )
					{
						// Destroy alien laser
						(*it).Eraser();
						IncAlienLaserCount();
						RemoveAlienLaser( it );
						delete it;

						// Destroy barrier
						(*it2).Eraser();
						RemoveBarrier( it2 );
						delete it2;
						break;
					}
				}
			}
		}

		if( death )
		{
			return true;
		}

		return false;
	}

	void GameObjectManager::CollidePlayerLasers()
	{
		// Check player lasers
		for( auto it : playerLasers )
		{
			// Player position
			Vector2D pos = (*it).GetPos();

			// Detect player laser collides with alien ship
			for( auto it2 : alienShips )
			{
				Vector2D pos2 = (*it2).GetPos();
				bool collide = pos.IntCmp( pos2 );
				if( collide )
				{
					// Destroy player laser
					IncPlayerLaserCount();
					RemovePlayerLaser( it );
					m_playerShip->ResetShot();
					delete it;

					// Check to kill alien
					bool dead = (*it2).DecreaseHealth();
					if( dead )
					{
						// Update score
						AlienShip* ship = static_cast<AlienShip*>(it2);
						AlienState state = ship->GetAlienState();
						Engine::Instance().ScoreManager().Update( state );

						Explosion* ex = Engine::Instance().GameObjectFactory().CreateExplosion( pos );
						AddExplosion( ex );
						ex->Render();

						// Power UP
						float test = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
						if( 0 == m_PowerUpCount )
						{
							// Destroyed enemies have 10% chance to drop power up
							float test1 = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
							if( test1 < 0.1f )
							{
								int test2 = Engine::Instance().RandomManager().Next( 1, 3 );
								m_PowerUpGet = static_cast<PowerUpType>( test2 );

								IncPowerUpCount();
								PowerUp* pu = Engine::Instance().GameObjectFactory().CreatePowerUp( m_PowerUpGet, it2->GetPosX(), it2->GetPosY() + 1 );
								AddPowerUp( pu );
								pu->Render();
							}
						}

						// Create alien wave
						if( test > 0.9f )
						{
							CreateAlienWaves();
						}

						// Destroy alien ship
						RemoveAlienShip( it2 );
						delete it2;
					}

					// If player laser collides with anything then break otherwise potential crash!
					break;
				}
			}

			// Detect player laser collides with alien laser
			for( auto it2 : alienLasers )
			{
				Vector2D pos2 = (*it2).GetPos();
				bool collide = pos.IntCmp( pos2 );
				if( collide )
				{
					// Destroy player laser
					(*it).Eraser();
					IncPlayerLaserCount();
					RemovePlayerLaser( it );
					m_playerShip->ResetShot();
					delete it;

					// Destroy alien laser
					(*it2).Eraser();
					IncAlienLaserCount();
					RemoveAlienLaser( it2 );
					delete it2;
					break;
				}
			}

			// Detect player laser collides with barrier
			if( 20 == (int)pos.y || 21 == (int)pos.y )
			{
				for( auto it2 : barriers )
				{
					Vector2D pos2 = (*it2).GetPos();
					bool collide = pos.IntCmp( pos2 );
					if( collide )
					{
						// Destroy player laser
						(*it).Eraser();
						IncPlayerLaserCount();
						RemovePlayerLaser( it );
						m_playerShip->ResetShot();
						delete it;

						// Destroy barrier
						(*it2).Eraser();
						RemoveBarrier( it2 );
						delete it2;
						break;
					}
				}
			}

		}
	}


	void GameObjectManager::Render()
	{
		if( nullptr != m_playerShip )
		{
			m_playerShip->Render();
		}
		for( auto it : alienShips )
		{
			it->Render();
		}
		for( auto it : playerLasers )
		{
			it->Render();
		}
		for( auto it : alienLasers )
		{
			it->Render();
		}
		
		for( auto it : explosions )
		{
			it->Render();
		}
	}

	void GameObjectManager::RenderBarriers()
	{
		for( auto it : barriers )
		{
			it->Render();
		}
	}

	void GameObjectManager::AddPlayerShip( PlayerShip* playerShip )
	{
		m_playerShip = playerShip;
	}
	void GameObjectManager::AddAlienShip( GameObject* newObj )
	{
		alienShips.push_back( newObj );
	}
	void GameObjectManager::AddPlayerLaser( GameObject* newObj )
	{
		playerLasers.push_back( newObj );
	}
	void GameObjectManager::AddAlienLaser( GameObject* newObj )
	{
		alienLasers.push_back( newObj );
	}
	void GameObjectManager::AddExplosion( GameObject* newObj )
	{
		explosions.push_back( newObj );
	}
	void GameObjectManager::AddBarrier( GameObject* newObj )
	{
		barriers.push_back( newObj );
	}
	void GameObjectManager::AddPowerUp( GameObject* newObj )
	{
		powerUps.push_back( newObj );
	}

	void GameObjectManager::RemoveAlienShip( GameObject* newObj )
	{
		RemoveObjectFromCollection( alienShips, newObj );
	}
	void GameObjectManager::RemovePlayerLaser( GameObject* newObj )
	{
		RemoveObjectFromCollection( playerLasers, newObj );
	}
	void GameObjectManager::RemoveAlienLaser( GameObject* newObj )
	{
		RemoveObjectFromCollection( alienLasers, newObj );
	}
	void GameObjectManager::RemoveExplosion( GameObject* newObj )
	{
		RemoveObjectFromCollection( explosions, newObj );
	}
	void GameObjectManager::RemoveBarrier( GameObject* newObj )
	{
		RemoveObjectFromCollection( barriers, newObj );
	}
	void GameObjectManager::RemovePowerUp( GameObject* newObj )
	{
		RemoveObjectFromCollection( powerUps, newObj );
	}
	void GameObjectManager::RemoveObjectFromCollection( std::vector<GameObjPtr>& collection, GameObject* newObj )
	{
		auto it = std::find_if( collection.begin(), collection.end(), [&]( GameObjPtr in )
		{
			return (in == newObj);
		} );

		collection.erase( it );
	}

	void GameObjectManager::RemovePlayerShip()
	{
		if( nullptr != m_playerShip )
		{
			delete m_playerShip;
			m_playerShip = nullptr;
		}
	}

	void GameObjectManager::RemoveAllFromCollection( std::vector<GameObjPtr>& collection )
	{
		std::vector<GameObject*>::const_iterator it;
		for( it = collection.begin(); it != collection.end(); )
		{
			GameObject* gameObject = *it;
			if( nullptr != gameObject )
			{
				delete gameObject;
				gameObject = nullptr;
				it = collection.erase( it );
			}
		}
	}

	void GameObjectManager::RemoveAlienShips()
	{
		RemoveAllFromCollection( alienShips );
	}
	void GameObjectManager::RemovePlayerLasers()
	{
		RemoveAllFromCollection( playerLasers );
	}
	void GameObjectManager::RemoveAlienLasers()
	{
		RemoveAllFromCollection( alienLasers );
	}
	void GameObjectManager::RemoveBarriers()
	{
		RemoveAllFromCollection( barriers );
	}
	void GameObjectManager::RemoveExplosions()
	{
		RemoveAllFromCollection( explosions );
	}
	void GameObjectManager::RemovePowerUps()
	{
		RemoveAllFromCollection( powerUps );
	}

	void GameObjectManager::Init( short screenWidth, short screenHeight, short playerShipHeight, short playerShipSpeed, short playerShipDelay, short wavesShipStart, short alienShipStart, short alienShipDepth, short alienShipSpeed, short playerLaserSpeed, short alienLaserSpeed, short explosionDelay )
	{
		m_ScreenWidth = screenWidth;
		m_ScreenHeight = screenHeight;
		m_PlayerShipHeight = playerShipHeight;
		m_PlayerShipSpeed = playerShipSpeed;
		m_PlayerShipDelay = playerShipDelay;
		m_WavesShipStart = wavesShipStart;
		m_AlienShipStart = alienShipStart;
		m_AlienShipDepth = alienShipDepth;
		m_AlienShipSpeed = alienShipSpeed;
		m_PlayerLaserSpeed = playerLaserSpeed;
		m_AlienLaserSpeed = alienLaserSpeed;
		m_ExplosionDelay = explosionDelay;
	}

	void GameObjectManager::CreateAll()
	{
		CreatePlayerShip();
		CreateAlienShips();
		CreateBarriers();

		// Set laser counts
		short playerLaserCount = Engine::Instance().ConfigManager().GetConfig( PLAYERLASER_COUNT );
		short alienLaserCount = Engine::Instance().ConfigManager().GetConfig( ALIENLASER_COUNT );

		m_PlayerLaserCount = playerLaserCount;
		m_AlienLaserCount = alienLaserCount;
		m_PowerUpCount = 0;
		m_PowerUpGet = PU_NONE;
		m_PowerUpUse = PU_NONE;
	}

	void GameObjectManager::CreatePlayerShip()
	{
		PlayerShip* p = Engine::Instance().GameObjectFactory().CreatePlayerShip();
		AddPlayerShip( p );
	}
	void GameObjectManager::CreateAlienShips()
	{
		short alienShipCount = Engine::Instance().ConfigManager().GetConfig( ALIENSHIP_COUNT );
		for( short index = 0; index < alienShipCount; index++ )
		{
			short aPosX = Engine::Instance().RandomManager().Next( 0, m_ScreenWidth - 1 );
			short aPosY = Engine::Instance().RandomManager().Next( m_AlienShipStart, m_AlienShipStart + m_AlienShipDepth - 1 );

			AlienShip* a = Engine::Instance().GameObjectFactory().CreateAlienShip( aPosX, aPosY );
			AddAlienShip( a );
		}
	}
	void GameObjectManager::CreateAlienWaves()
	{
		short wavesShipSize = Engine::Instance().ConfigManager().GetConfig( WAVESSHIP_SIZE );

		short doubleSize = 2 * wavesShipSize;
		short aPosX = Engine::Instance().RandomManager().Next( doubleSize, m_ScreenWidth - 1 - doubleSize );
		short aPosY = Engine::Instance().RandomManager().Next( m_WavesShipStart, m_WavesShipStart + m_AlienShipDepth - 1 );
		for( short index = 0; index < wavesShipSize; index++ )
		{
			AlienShip* a = Engine::Instance().GameObjectFactory().CreateAlienShip( aPosX, aPosY );
			AddAlienShip( a );
			aPosX += 2;;
		}
	}
	void GameObjectManager::CreateBarriers()
	{
		// Prefer to make these values configurable NOT hard coded!
		short xx = 12;
		for( short z = 0; z < 4; z++ )
		{
			for( short x = xx; x < xx + 6; x++ )
			{
				for( short y = 20; y < 22; y++ )
				{
					Barrier* b = Engine::Instance().GameObjectFactory().CreateBarrier( x, y );
					AddBarrier( b );
				}
			}

			xx += 17;
		}
	}

	void GameObjectManager::RemoveAll()
	{
		RemovePlayerShip();
		RemoveAlienShips();
		RemovePlayerLasers();
		RemoveAlienLasers();
		RemoveBarriers();
		RemoveExplosions();
		RemovePowerUps();
	}

	void GameObjectManager::Quit()
	{
		RemoveAll();
	}
}