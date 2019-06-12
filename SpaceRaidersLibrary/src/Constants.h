#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

namespace SpaceRaiders
{
	const short MAX_SCREENS = 3;

	const char LOG_FILENAME[8] = "log.txt";
	const char CONFIG_FILENAME[11] = "config.txt";
	const char SCORE_FILENAME[12] = "hiscore.txt";

	enum GameMode
	{
		GM_Manual = 0,
		GM_Automatic
	};

	enum ConfigType
	{
		GAME_MODE,
		FPS_CONFIG,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		PLAYERSHIP_HEIGHT,
		PLAYERSHIP_SPEED,
		PLAYERSHIP_DELAY,
		WAVESSHIP_START,
		WAVESSHIP_SIZE,
		ALIENSHIP_COUNT,
		ALIENSHIP_START,
		ALIENSHIP_DEPTH,
		ALIENSHIP_SPEED,
		PLAYERLASER_COUNT,
		PLAYERLASER_SPEED,
		ALIENLASER_COUNT,
		ALIENLASER_SPEED,
		EXPLOSION_DELAY,
		ENERGY_TIMER,
		START_SCREEN,
	};

	enum ScreenType
	{
		LOAD_SCREEN,
		PLAY_SCREEN,
		OVER_SCREEN
	};

	enum SpriteAction
	{
		SA_NONE = 0,
		SA_KILL = 1,
		SA_ADD = 2,
		SA_DIE = 4,
	};

	enum ObjectType
	{
		OT_GameObject,
		OT_AlienShip,
		OT_AlienLaser,
		OT_PlayerShip,
		OT_PlayerLaser,
		OT_Explosion,
		OT_Barrier,
		OT_PowerUpOne,
		OT_PowerUpTwo,
		OT_PowerUpThree,
		//OT_PowerUpFour,
		//OT_PowerUpFive
	};

	enum RaiderSprites
	{
		RS_BackgroundTile = 0xB0,
		RS_Player = 'P',
		RS_Alien = 'A',
		RS_BetterAlien = 'B',
		RS_PlayerLaserOne = 0xBA,
		RS_PlayerLaserTwo = 0x5C,
		RS_PlayerLaserThree = 0x2F,
		RS_AlienLaser = '|',
		RS_Explosion = '*',
		RS_Barrier = 'X',
		RS_PowerUpOne = '1',
		RS_PowerUpTwo = '2',
		RS_PowerUpThree = '3',
		//RS_PowerUpFour = '4',
		//RS_PowerUpFive = 'O'
	};

	enum AlienState
	{
		AS_Normal,
		AS_Better
	};

	enum LaserType
	{
		LT_Single,
		LT_Triple
	};

	enum PowerUpType
	{
		PU_NONE,
		PU_One,
		PU_Two,
		PU_Three,
		//PU_Four,
		//PU_Five
	};

}

#endif//_CONSTANTS_H_
