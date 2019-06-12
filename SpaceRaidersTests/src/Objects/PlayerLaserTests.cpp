#include "gtest/gtest.h"
#include "Objects/PlayerLaser.h"

using namespace testing;
using namespace SpaceRaiders;

class PlayerLaserTests : public ::testing::Test
{
public:
	PlayerLaserTests() {}
	~PlayerLaserTests() {}
protected:
	PlayerLaser playerLaser;
};

TEST_F( PlayerLaserTests, Init )
{
	PlayerLaser& pl = *(new PlayerLaser);
	pl.SetPos( Vector2D( 40, 25 ) );
	pl.SetVel( Vector2D( 50, 0 ) );
	pl.SetMaxX( 80 );
	delete &pl;

}