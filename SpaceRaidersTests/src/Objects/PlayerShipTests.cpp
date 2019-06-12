#include "gtest/gtest.h"
#include "Objects/PlayerShip.h"
#include "Constants.h"

using namespace testing;
using namespace SpaceRaiders;

class PlayerShipTests : public ::testing::Test
{
public:
	PlayerShipTests() {}
	~PlayerShipTests() {}
protected:
	PlayerShip playerShip;
};

TEST_F( PlayerShipTests, Init )
{
	PlayerShip& p = *(new PlayerShip);
	p.SetPos( Vector2D( 40, 25 ) );
	p.SetVel( Vector2D( 50, 0 ) );
	p.SetMaxX( 80 );
	delete &p;
}

TEST_F( PlayerShipTests, GetLaserType )
{
	PlayerShip& p = *(new PlayerShip);
	LaserType laserType = p.GetLaserType();
	ASSERT_EQ( LT_Single, laserType );
	delete &p;
}

TEST_F( PlayerShipTests, SwitchLaser )
{
	PlayerShip& p = *(new PlayerShip);
	p.SwitchLaser();
	LaserType laserType = p.GetLaserType();
	ASSERT_EQ( LT_Triple, laserType );
	delete &p;
}