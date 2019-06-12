#ifndef _FRAME_MANAGER_H_
#define _FRAME_MANAGER_H_

namespace SpaceRaiders
{
	class FrameManager
	{
	public:
		FrameManager() {}
		~FrameManager() {}

		int GetTickCount();
	};
}

#endif//_FRAME_MANAGER_H_