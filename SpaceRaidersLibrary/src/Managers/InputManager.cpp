#include "InputManager.h"
#include <Windows.h>
#include "../Engine.h"

namespace SpaceRaiders
{
	void InputManager::Init( short gameMode )
	{
		m_gameMode = gameMode;
	}

	bool InputManager::Escape()
	{
		return GetAsyncKeyState( VK_ESCAPE ) < 0;
	}

	bool InputManager::Return()
	{
		return GetAsyncKeyState( VK_RETURN) < 0;
	}

	bool InputManager::Quit()
	{
		return GetAsyncKeyState( 'Q' ) < 0;
	}
	bool InputManager::Exit()
	{
		return GetAsyncKeyState( 'X' ) < 0;
	}

	// Important : if had more time would re-factor this into
	// 2x input managers i.e. one for manual {random} and auto
	bool InputManager::Left()
	{
		if( GM_Manual == m_gameMode )
		{
			float data = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
			return data < 0.3f;
		}

		return GetAsyncKeyState( VK_LEFT ) < 0;
	}

	bool InputManager::Right()
	{
		if( GM_Manual == m_gameMode )
		{
			float data = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
			return data < 0.4f;
		}

		return GetAsyncKeyState( VK_RIGHT ) < 0;
	}

	bool InputManager::Space()
	{
		if( GM_Manual == m_gameMode )
		{
			float data = Engine::Instance().RandomManager().Next( 0.0f, 1.0f );
			return data < 0.5f;
		}

		return GetAsyncKeyState( VK_SPACE ) < 0;
	}
}