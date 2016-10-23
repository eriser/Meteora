#include "SquareWave.h"

namespace Meteora
{
	SquareWave::SquareWave()
	{
	}


	SquareWave::~SquareWave()
	{
	}
	const float SquareWave::generateSound(const float phase)
	{
		return phase >= M_PI ? 1.0f : 0.0f;
	}
}