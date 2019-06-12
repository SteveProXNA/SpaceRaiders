#include "GameObject.h"
#include "../Engine.h"

namespace SpaceRaiders
{
	void GameObject::Render()
	{
		Engine::Instance().RenderManager().Render( m_pos.x, m_pos.y, sprite );
	}

	void GameObject::Eraser()
	{
		Engine::Instance().RenderManager().Render( m_pos.x, m_pos.y, RS_BackgroundTile );
	}
}