#ifndef _POWERUP_H_
#define _POWERUP_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class PowerUp : public GameObject
	{
	public:
		PowerUp() {}
		~PowerUp() {}

		SpriteAction Update( float delta ) override;
	};

	class PowerUpOne : public PowerUp
	{
	public:
		PowerUpOne()
		{
			m_objType = OT_PowerUpOne;
			sprite = RS_PowerUpOne;
		}
		~PowerUpOne() {}
	};

	class PowerUpTwo : public PowerUp
	{
	public:
		PowerUpTwo()
		{
			m_objType = OT_PowerUpTwo;
			sprite = RS_PowerUpTwo;
		}
		~PowerUpTwo() {}
	};

	class PowerUpThree: public PowerUp
	{
	public:
		PowerUpThree()
		{
			m_objType = OT_PowerUpThree;
			sprite = RS_PowerUpThree;
		}
		~PowerUpThree() {}
	};
}

#endif//_POWERUP_H_