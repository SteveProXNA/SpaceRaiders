#ifndef _PLAYERLASER_H_
#define _PLAYERLASER_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class PlayerLaser : public GameObject
	{
	public:
		PlayerLaser()
		{
		}
		~PlayerLaser() {}

		SpriteAction Update( float delta ) override;
	};

	class PlayerLaserOne : public PlayerLaser
	{
	public:
		PlayerLaserOne()
		{
			m_objType = OT_PlayerLaser;
			sprite = RS_PlayerLaserOne;
		}
		~PlayerLaserOne() {}
	};

	class PlayerLaserTwo: public PlayerLaser
	{
	public:
		PlayerLaserTwo()
		{
			m_objType = OT_PlayerLaser;
			sprite = RS_PlayerLaserTwo;
		}
		~PlayerLaserTwo() {}
	};

	class PlayerLaserThree : public PlayerLaser
	{
	public:
		PlayerLaserThree()
		{
			m_objType = OT_PlayerLaser;
			sprite = RS_PlayerLaserThree;
		}
		~PlayerLaserThree() {}
	};
}

#endif//_PLAYERLASER_H_