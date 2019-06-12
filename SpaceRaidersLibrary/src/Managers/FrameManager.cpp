#include "FrameManager.h"
#include <Windows.h>

namespace SpaceRaiders
{
	int FrameManager::GetTickCount()
	{
		return ::GetTickCount();
	}

}