#include "gtest/gtest.h"
#include "Managers/TextManager.h"

using namespace testing;
using namespace SpaceRaiders;

class TextManagerTests : public ::testing::Test
{
public:
	TextManagerTests() {}
	~TextManagerTests() {}
protected:
	TextManager textManager;
};

TEST_F( TextManagerTests, Title )
{
	//textManager.Title();
}