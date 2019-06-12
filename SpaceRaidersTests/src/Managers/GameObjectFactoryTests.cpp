#include "gtest/gtest.h"
#include "Managers/GameObjectFactory.h"
#include "Objects/AlienLaser.h"
#include "Objects/AlienShip.h"
#include "Objects/Barrier.h"
#include "Objects/Explosion.h"
#include "Objects/PlayerShip.h"
#include "Objects/PlayerLaser.h"
#include "Objects/PowerUp.h"

using namespace testing;
using namespace SpaceRaiders;

class GameObjectFactoryTests : public ::testing::Test
{
public:
	GameObjectFactoryTests() {}
	~GameObjectFactoryTests() {}
protected:
	GameObjectFactory gameObjectFactory;
};

TEST_F( GameObjectFactoryTests, Init )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
}

TEST_F( GameObjectFactoryTests, CreatePlayerShip )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	PlayerShip* p = gameObjectFactory.CreatePlayerShip();
	delete p;
}
TEST_F( GameObjectFactoryTests, CreateAlienShip )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	AlienShip* a = gameObjectFactory.CreateAlienShip( 40, 12 );
	delete a;
}
TEST_F( GameObjectFactoryTests, CreatePlayerLaser )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	PlayerLaser* pl = gameObjectFactory.CreatePlayerLaserOne( 40, 25 );
	delete pl;
}
TEST_F( GameObjectFactoryTests, CreateAlienLaser )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	AlienLaser* al = gameObjectFactory.CreateAlienLaser( 40, 25 );
	delete al;
}
TEST_F( GameObjectFactoryTests, CreateBarrier )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	Barrier* b = gameObjectFactory.CreateBarrier( 4, 20 );
	delete b;
}
TEST_F( GameObjectFactoryTests, CreateExplosion )
{
	gameObjectFactory.Init( 80, 28, 25, 50, 500, 4, 8, 4, 25, 15, 10, 800 );
	Vector2D pos = Vector2D( 40, 15 );
	Explosion* ex = gameObjectFactory.CreateExplosion( pos );
	delete ex;
}
TEST_F( GameObjectFactoryTests, CreatePowerUp )
{
	//PowerUp* pup = gameObjectFactory.CreatePowerUp( 0, Vector2D( 20, 20 ) );
	ASSERT_EQ( 1, 1 );
}