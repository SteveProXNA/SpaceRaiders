#include "RandomManager.h"
#include <random>

std::default_random_engine rGen;
typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

namespace SpaceRaiders
{
	void RandomManager::Init( unsigned int seed )
	{
		rGen.seed( seed );
	}

	int RandomManager::Next( int min, int max )
	{
		intRand data( min, max );
		return data( rGen );
	}

	float RandomManager::Next( float min, float max )
	{
		floatRand data( min, max );
		return data( rGen );
	}

}