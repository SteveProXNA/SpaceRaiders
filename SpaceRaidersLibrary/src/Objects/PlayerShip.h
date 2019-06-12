#ifndef _PLAYERSHIP_H_
#define _PLAYERSHIP_H_

#include "GameObject.h"

namespace SpaceRaiders
{
	class PlayerShip : public GameObject
	{
	public:
		PlayerShip()
		{
			m_objType = OT_PlayerShip;
			sprite = RS_Player; 
			timer = 0;
			isShooting = false;
			laserType = LT_Single;
		}
		~PlayerShip() {}

		SpriteAction Update( float delta ) override;

		inline void ResetShot() { isShooting = false; }
		inline float GetDelay() const { return m_delay; }
		inline void SetDelay( float delay ) { m_delay = delay; }
		LaserType GetLaserType() const { return laserType; }
		void SwitchLaser();

	private:
		float m_delay;
		float timer;
		bool isShooting;
		LaserType laserType;
	};

}

#endif//_PLAYERSHIP_H_