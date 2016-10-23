#include "TriangleWave.h"

namespace Meteora
{

	TriangleWave::TriangleWave()
	{
	}


	TriangleWave::~TriangleWave()
	{
	}

	const float TriangleWave::generateSound(const float phase)
	{
		return phase <= M_PI ? phase / M_TWOPI : -phase / M_TWOPI;
	}

}