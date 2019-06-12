#include "gtest/gtest.h"
#include "Objects/Barrier.h"

using namespace testing;
using namespace SpaceRaiders;

class BarrierTests : public ::testing::Test
{
public:
	BarrierTests() {}
	~BarrierTests() {}
protected:
	Barrier barrier;
};

TEST_F( BarrierTests, Init )
{
	Barrier& b = *(new Barrier);
	delete &b;
}