#include "gtest/gtest.h"
#include "Objects/Explosion.h"

using namespace testing;
using namespace SpaceRaiders;

class ExplosionTests : public ::testing::Test
{
public:
	ExplosionTests() {}
	~ExplosionTests() {}
protected:
	Explosion explosion;
};

TEST_F( ExplosionTests, Init )
{
	ASSERT_EQ( 1, 1 );
}