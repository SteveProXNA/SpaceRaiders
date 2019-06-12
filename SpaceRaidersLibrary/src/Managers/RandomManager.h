#ifndef _RANDOM_MANAGER_H_
#define _RANDOM_MANAGER_H_

namespace SpaceRaiders
{
	class RandomManager
	{
	public:
		RandomManager() {}
		~RandomManager() {}

		void Init( unsigned int seed = 0 );
		int Next( int min, int max );
		float Next( float min, float max );
	};
}

#endif//_RANDOM_MANAGER_H_