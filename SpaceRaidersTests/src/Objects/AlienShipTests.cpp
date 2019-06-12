#include "gtest/gtest.h"
#include "Objects/AlienShip.h"

using namespace testing;
using namespace SpaceRaiders;

class AlienShipTests : public ::testing::Test
{
public:
	AlienShipTests() {}
	~AlienShipTests() {}
protected:
	AlienShip alienShip;
};

TEST_F( AlienShipTests, Init )
{
	AlienShip& a = *(new AlienShip);
	a.SetPos( Vector2D( 35, 12 ) );
	a.SetVel( Vector2D( 25, 0 ) );
	a.SetMaxX( 80 );
	delete &a;
}