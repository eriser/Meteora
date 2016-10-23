#include "Sawtooth.h"

namespace Meteora
{

	Sawtooth::Sawtooth()
	{
	}


	Sawtooth::~Sawtooth()
	{
	}

	const float Sawtooth::generateSound(const float phase)
	{
		// avoid division by 0.
		return phase != 0.0f ? phase / M_TWOPI : 0.0f;
	}

}