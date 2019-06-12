#include "gtest/gtest.h"
#include "Objects/PowerUp.h"

using namespace testing;
using namespace SpaceRaiders;

class PowerUpTests : public ::testing::Test
{
public:
	PowerUpTests() {}
	~PowerUpTests() {}
protected:
	PowerUp powerUp;
};

TEST_F( PowerUpTests, Init )
{
}