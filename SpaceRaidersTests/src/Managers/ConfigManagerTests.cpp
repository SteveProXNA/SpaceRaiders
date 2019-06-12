#include "gtest/gtest.h"
#include "Managers/ConfigManager.h"
#include "Constants.h"

using namespace testing;
using namespace SpaceRaiders;

class ConfigManagerTests : public ::testing::Test
{
public:
	ConfigManagerTests() {}
	~ConfigManagerTests() {}
protected:
	ConfigManager configManager;
};

TEST_F( ConfigManagerTests, Init )
{
	configManager.Init();
	ASSERT_EQ( 50, configManager.GetConfig( FPS_CONFIG ) );
	ASSERT_EQ( 80, configManager.GetConfig( SCREEN_WIDTH ) );
	ASSERT_EQ( 28, configManager.GetConfig( SCREEN_HEIGHT ) );
}