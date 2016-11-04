#include "TriangleWave.h"

namespace Meteora
{

	TriangleWave::TriangleWave()
	{
	}


	TriangleWave::~TriangleWave()
	{
	}

	const Sound TriangleWave::generateSound(const Phase phase)
	{
		return phase <= M_PI ? phase / M_TWOPI : -phase / M_TWOPI;
	}

}