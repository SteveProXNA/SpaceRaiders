#include "gtest/gtest.h"
#include "Managers/FrameManager.h"

using namespace testing;
using namespace SpaceRaiders;

class FrameManagerTests : public ::testing::Test
{
public:
	FrameManagerTests() {}
	~FrameManagerTests() {}
protected:
	FrameManager frameManager;
};

TEST_F( FrameManagerTests, GetTickCount )
{
	int tickCount = frameManager.GetTickCount();
	ASSERT_TRUE( tickCount > 0 );
}