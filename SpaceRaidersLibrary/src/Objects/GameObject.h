#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "../Constants.h"
#include "../Vector2D.h"

namespace SpaceRaiders
{
	class GameObject
	{
	public:
		virtual SpriteAction Update( float delta ) = 0;
		void Render();
		void Eraser();
		virtual bool DecreaseHealth() { return true; };

		inline Vector2D GetPos() const { return m_pos; }
		inline Vector2D GetVel() const { return m_vel; }
		inline float GetPosX() const { return m_pos.x; }
		inline float GetPosY() const { return m_pos.y; }
		inline short GetMaxX() const { return m_maxX; }
		inline short GetMinY() const { return m_minY; }
		inline short GetMaxY() const { return m_maxY; }
		inline void SetPos( Vector2D pos ) { m_pos = pos; }
		inline void SetPosX( float x ) { m_pos.x = x; }
		inline void SetPosY( float y ) { m_pos.y = y; }
		inline void SetMaxX( short maxX ) { m_maxX = maxX - 1; }
		inline void SetMinY( short minY ) { m_minY = minY; }
		inline void SetMaxY( short maxY ) { m_maxY = maxY; }
		inline void SetVel( Vector2D vel ) { m_vel = vel; }
		inline ObjectType GetObjectType() const { return m_objType; }

	protected:
		ObjectType m_objType = OT_GameObject;
		unsigned char sprite;
		Vector2D m_pos;
		Vector2D m_vel;

		short m_maxX, m_minY, m_maxY;
	};

}

#endif//_GAMEOBJECT_H_