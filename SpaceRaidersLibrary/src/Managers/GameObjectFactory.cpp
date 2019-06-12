#include "GameObjectFactory.h"

namespace SpaceRaiders
{
	void GameObjectFactory::Init( short screenWidth, short screenHeight, short playerShipHeight, short playerShipSpeed, short playerShipDelay, short wavesShipStart, short alienShipStart, short alienShipDepth, short alienShipSpeed, short playerLaserSpeed, short alienLaserSpeed, short explosionDelay )
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

	PlayerShip* GameObjectFactory::CreatePlayerShip()
	{
		PlayerShip* p = new PlayerShip;
		Vector2D pos = Vector2D( m_ScreenWidth / 2.0f, m_PlayerShipHeight );
		Vector2D vel = Vector2D( m_PlayerShipSpeed, 0 );
		p->SetPos( pos );
		p->SetVel( vel );
		p->SetMaxX( m_ScreenWidth );
		p->SetDelay( m_PlayerShipDelay );
		return p;
	}

	AlienShip* GameObjectFactory::CreateAlienShip( float posX, float posY )
	{
		AlienShip* a = new AlienShip();
		Vector2D pos = Vector2D( posX, posY );
		Vector2D vel = Vector2D( m_AlienShipSpeed, 0 );
		a->SetPos( pos );
		a->SetVel( vel );
		a->SetMaxX( m_ScreenWidth );
		a->SetMaxY( m_PlayerShipHeight );
		return a;
	}

	PlayerLaser* GameObjectFactory::CreatePlayerLaserOne( float posX, float posY )
	{
		PlayerLaserOne* pl = new PlayerLaserOne();
		Vector2D pos = Vector2D( posX, posY );
		Vector2D vel = Vector2D( 0, -(float)m_PlayerLaserSpeed );
		pl->SetPos( pos );
		pl->SetVel( vel );
		pl->SetMaxX( m_ScreenWidth );
		pl->SetMinY( m_WavesShipStart );
		return pl;
	}
	PlayerLaser* GameObjectFactory::CreatePlayerLaserTwo( float posX, float posY )
	{
		PlayerLaserTwo* pl = new PlayerLaserTwo();
		Vector2D pos = Vector2D( posX , posY );
		Vector2D vel = Vector2D( -(float)m_PlayerLaserSpeed, -(float)m_PlayerLaserSpeed );
		pl->SetPos( pos );
		pl->SetVel( vel );
		pl->SetMaxX( m_ScreenWidth );
		pl->SetMinY( m_WavesShipStart );
		return pl;
	}
	PlayerLaser* GameObjectFactory::CreatePlayerLaserThree( float posX, float posY )
	{
		PlayerLaserThree* pl = new PlayerLaserThree();
		Vector2D pos = Vector2D( posX + 1, posY );
		Vector2D vel = Vector2D( (float)m_PlayerLaserSpeed, -(float)m_PlayerLaserSpeed );
		pl->SetPos( pos );
		pl->SetVel( vel );
		pl->SetMaxX( m_ScreenWidth );
		pl->SetMinY( m_WavesShipStart );
		return pl;
	}

	AlienLaser* GameObjectFactory::CreateAlienLaser( float posX, float posY )
	{
		AlienLaser* al = new AlienLaser();
		Vector2D pos = Vector2D( posX, posY );
		Vector2D vel = Vector2D( 0, (float)m_AlienLaserSpeed );
		al->SetPos( pos );
		al->SetVel( vel );
		al->SetMaxX( m_ScreenWidth );
		al->SetMaxY( m_PlayerShipHeight );
		return al;
	}

	Barrier* GameObjectFactory::CreateBarrier( float posX, float posY )
	{
		Barrier* b = new Barrier;
		Vector2D pos = Vector2D( posX, posY );
		b->SetPos( pos );
		return b;
	}

	Explosion* GameObjectFactory::CreateExplosion( Vector2D pos )
	{
		Explosion* ex = new Explosion;
		ex->SetPos( pos );
		ex->SetDelay( m_ExplosionDelay );
		return ex;
	}

	PowerUp* GameObjectFactory::CreatePowerUp( PowerUpType powerUpType, float posX, float posY )
	{
		PowerUp* pu = nullptr;
		if( PU_One == powerUpType )
		{
			pu = new PowerUpOne();
		}
		if( PU_Two == powerUpType )
		{
			pu = new PowerUpTwo();
		}
		if( PU_Three == powerUpType )
		{
			pu = new PowerUpThree();
		}

		Vector2D pos = Vector2D( posX, posY );
		Vector2D vel = Vector2D( 0, (float)m_AlienLaserSpeed );
		pu->SetPos( pos );
		pu->SetVel( vel );
		pu->SetMaxX( m_ScreenWidth );
		pu->SetMaxY( m_PlayerShipHeight );
		return pu;
	}
}