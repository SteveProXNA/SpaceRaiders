#include "gtest/gtest.h"
#include "Objects/AlienLaser.h"

using namespace testing;
using namespace SpaceRaiders;

class AlienLaserTests : public ::testing::Test
{
public:
	AlienLaserTests() {}
	~AlienLaserTests() {}
protected:
	AlienLaser alienLaser;
};

TEST_F( AlienLaserTests, Init )
{
	AlienLaser& al = *(new AlienLaser);
	delete &al;
}