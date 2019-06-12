#include "gtest/gtest.h"
#include "Managers/ScoreManager.h"
#include "Constants.h"

using namespace testing;
using namespace SpaceRaiders;

class ScoreManagerTests : public ::testing::Test
{
public:
	ScoreManagerTests() {}
	~ScoreManagerTests() {}
protected:
	ScoreManager scoreManager;
};

TEST_F( ScoreManagerTests, Init )
{
	scoreManager.Init();
}

TEST_F( ScoreManagerTests, Reset )
{
	scoreManager.Reset();
}

TEST_F( ScoreManagerTests, Update )
{
	//scoreManager.Update( 10 );
	scoreManager.Update( AS_Better );
}

TEST_F( ScoreManagerTests, Quit )
{
	scoreManager.Quit();
}