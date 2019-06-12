#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

namespace SpaceRaiders
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		void Init( short gameMode );
		bool Escape();
		bool Return();
		bool Quit();
		bool Exit();
		bool Left();
		bool Right();
		bool Space();

	private:
		short m_gameMode;
	};
}

#endif//_INPUT_MANAGER_H_