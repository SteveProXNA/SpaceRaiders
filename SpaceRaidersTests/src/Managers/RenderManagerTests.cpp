#include "gtest/gtest.h"
#include "Managers/RenderManager.h"

using namespace testing;
using namespace SpaceRaiders;

class RenderManagerTests : public ::testing::Test
{
public:
	RenderManagerTests() {}
	~RenderManagerTests() {}
protected:
	RenderManager renderManager;
};

TEST_F( RenderManagerTests, Render )
{
	//renderManager.Render( 40, 27, RS_Player );
}