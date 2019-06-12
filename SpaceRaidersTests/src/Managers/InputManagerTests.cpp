#include "gtest/gtest.h"
#include "Managers/InputManager.h"

using namespace testing;
using namespace SpaceRaiders;

class InputManagerTests : public ::testing::Test
{
public:
	InputManagerTests() {}
	~InputManagerTests() {}
protected:
	InputManager inputManager;
};

TEST_F( InputManagerTests, Escape )
{
	ASSERT_EQ( false, inputManager.Escape() );
}
TEST_F( InputManagerTests, Return )
{
	ASSERT_EQ( false, inputManager.Return() );
}
TEST_F( InputManagerTests, Left )
{
	ASSERT_EQ( false, inputManager.Left() );
}
TEST_F( InputManagerTests, Right )
{
	ASSERT_EQ( false, inputManager.Right() );
}
TEST_F( InputManagerTests, Space )
{
	ASSERT_EQ( false, inputManager.Space() );
}