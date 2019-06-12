#include "gtest/gtest.h"
#include "Managers/ScreenManager.h"

using namespace testing;
using namespace SpaceRaiders;

class ScreenManagerTests : public ::testing::Test
{
public:
	ScreenManagerTests() {}
	~ScreenManagerTests() {}
protected:
	ScreenManager screenManager;
};

TEST_F( ScreenManagerTests, Test )
{
	//screenManager.Init();
	//screenManager.Quit();
}