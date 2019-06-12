#include "gtest/gtest.h"
#include "Managers/GameObjectManager.h"
#include "Objects/AlienLaser.h"
#include "Objects/AlienShip.h"
#include "Objects/Barrier.h"
#include "Objects/Explosion.h"
#include "Objects/PlayerShip.h"
#include "Objects/PlayerLaser.h"
#include "Objects/PowerUp.h"

using namespace testing;
using namespace SpaceRaiders;

class GameObjectManagerTests : public ::testing::Test
{
public:
	GameObjectManagerTests() {}
	~GameObjectManagerTests() {}
protected:
	GameObjectManager gameObjectManager;
};

TEST_F( GameObjectManagerTests, Init )
{
	//gameObjectManager.Init();
}
TEST_F( GameObjectManagerTests, AddPlayerShip )
{
	PlayerShip& p = *(new PlayerShip);
	gameObjectManager.AddPlayerShip( &p );
	GameObject* go = gameObjectManager.GetPlayerShip();
	delete &p;
}
TEST_F( GameObjectManagerTests, AddAlienShip )
{
	AlienShip& a = *(new AlienShip);
	gameObjectManager.AddAlienShip( &a );
	auto objs = gameObjectManager.GetAlienShips();
	ASSERT_TRUE( 1 == objs.size() );
	delete &a;
}
TEST_F( GameObjectManagerTests, AddPlayerLaser )
{
	PlayerLaser& pl = *(new PlayerLaser);
	gameObjectManager.AddPlayerLaser( &pl );
	delete &pl;
}
TEST_F( GameObjectManagerTests, AddAlienLaser )
{
	AlienLaser& al = *(new AlienLaser);
	gameObjectManager.AddAlienLaser( &al );
	delete &al;
}
TEST_F( GameObjectManagerTests, AddExplosion )
{
	Explosion& ex = *(new Explosion);
	gameObjectManager.AddExplosion( &ex );
	delete &ex;
}
TEST_F( GameObjectManagerTests, AddBarrier )
{
	Barrier& b = *(new Barrier);
	gameObjectManager.AddBarrier( &b );
	delete &b;
}
TEST_F( GameObjectManagerTests, AddPowerUp )
{
	PowerUp& pu = *(new PowerUpOne);
	gameObjectManager.AddPowerUp( &pu );
	delete &pu;
}

TEST_F( GameObjectManagerTests, RemoveAlienShip )
{
	AlienShip& a1 = *(new AlienShip);
	AlienShip& a2 = *(new AlienShip);
	gameObjectManager.AddAlienShip( &a1 );
	gameObjectManager.AddAlienShip( &a2 );
	gameObjectManager.RemoveAlienShip( &a1 );
}
TEST_F( GameObjectManagerTests, RemovePlayerLaser )
{
	PlayerLaser& pl1 = *(new PlayerLaser);
	PlayerLaser& pl2 = *(new PlayerLaser);
	gameObjectManager.AddPlayerLaser( &pl1 );
	gameObjectManager.AddPlayerLaser( &pl2 );
	gameObjectManager.RemovePlayerLaser( &pl1 );
}
TEST_F( GameObjectManagerTests, RemoveAlienLaser )
{
	AlienLaser& al1 = *(new AlienLaser);
	AlienLaser& al2 = *(new AlienLaser);
	gameObjectManager.AddAlienLaser( &al1 );
	gameObjectManager.AddAlienLaser( &al2 );
	gameObjectManager.RemoveAlienLaser( &al1 );
}
TEST_F( GameObjectManagerTests, RemoveExplosion )
{
	Explosion& ex1 = *(new Explosion);
	Explosion& ex2 = *(new Explosion);
	gameObjectManager.AddExplosion( &ex1 );
	gameObjectManager.AddExplosion( &ex2 );
	gameObjectManager.RemoveExplosion( &ex1 );
}
TEST_F( GameObjectManagerTests, RemoveBarrier )
{
	Barrier& b1 = *(new Barrier);
	Barrier& b2 = *(new Barrier);
	gameObjectManager.AddBarrier( &b1 );
	gameObjectManager.AddBarrier( &b2 );
	gameObjectManager.RemoveBarrier( &b1 );
}
TEST_F( GameObjectManagerTests, RemovePowerUp )
{
	PowerUp& pu = *(new PowerUpOne);
	gameObjectManager.AddPowerUp( &pu );
	gameObjectManager.RemovePowerUp( &pu );
}

TEST_F( GameObjectManagerTests, RemovePlayerShip )
{
	PlayerShip& p = *(new PlayerShip);
	gameObjectManager.AddPlayerShip( &p );
	gameObjectManager.RemovePlayerShip();
}
TEST_F( GameObjectManagerTests, RemoveAlienShips )
{
	AlienShip& a1 = *(new AlienShip);
	AlienShip& a2 = *(new AlienShip);
	gameObjectManager.AddAlienShip( &a1 );
	gameObjectManager.AddAlienShip( &a2 );
	gameObjectManager.RemoveAlienShips();
}

TEST_F( GameObjectManagerTests, Quit )
{
	PlayerShip& p = *(new PlayerShip);
	AlienShip& a = *(new AlienShip);
	gameObjectManager.AddPlayerShip( &p );
	gameObjectManager.AddAlienShip( &a );
	gameObjectManager.Quit();
}