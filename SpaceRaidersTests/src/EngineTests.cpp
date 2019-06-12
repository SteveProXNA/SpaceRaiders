#include "gtest/gtest.h"
#include "Engine.h"
#include "Constants.h"

using namespace SpaceRaiders;

TEST( EngineTests, ConfigManagerConfig )
{
	Engine::Instance().ConfigManager().Init();
	Engine::Instance().ConfigManager().Init();

	int fps = Engine::Instance().ConfigManager().GetConfig( FPS_CONFIG );
	ASSERT_EQ( 50, fps );
}

TEST( EngineTests, LogManagerWrite )
{
	Engine::Instance().LogManager().Init();
	Engine::Instance().LogManager().Write( "engine test" );
	Engine::Instance().LogManager().Quit();
}