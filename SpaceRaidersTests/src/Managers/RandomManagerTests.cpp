#include "gtest/gtest.h"
#include "Managers/RandomManager.h"

using namespace testing;
using namespace SpaceRaiders;

class RandomManagerTests : public ::testing::Test
{
public:
	RandomManagerTests() {}
	~RandomManagerTests() {}
protected:
	RandomManager randomManager;
};

TEST_F( RandomManagerTests, Next )
{
	randomManager.Init();

	int test1 = randomManager.Next( 0, 10 );
	ASSERT_TRUE( test1 > 0 );

	float test2 = (float)randomManager.Next( 0, 10 );
	ASSERT_TRUE( test2 > 0 );

	const float maxUpdateRate = 0.01f;
	float test3 = randomManager.Next( -maxUpdateRate, 2 * maxUpdateRate );
	ASSERT_TRUE( test3 > -0.01 && test3 < 0.04 );
}

TEST_F( RandomManagerTests, Loop )
{
	randomManager.Init();

	const int max = 10;
	for( int idx = 0; idx < max; idx++ )
	{
		int data = randomManager.Next( 1, 5 );
		int type = data * 2;
	}
}