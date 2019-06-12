#include "gtest/gtest.h"
#include "Managers/PowerUpManager.h"

using namespace testing;
using namespace SpaceRaiders;

class PowerUpManagerTests : public ::testing::Test
{
public:
	PowerUpManagerTests() {}
	~PowerUpManagerTests() {}
protected:
	PowerUpManager powerUpManager;
};

TEST_F( PowerUpManagerTests, Init )
{
	powerUpManager.Init();
}