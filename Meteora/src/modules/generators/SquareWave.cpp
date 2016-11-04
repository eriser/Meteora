#include "SquareWave.h"

namespace Meteora
{
	SquareWave::SquareWave()
	{
	}


	SquareWave::~SquareWave()
	{
	}
	const Sound SquareWave::generateSound(const Phase phase)
	{
		return phase >= M_PI ? 1.0f : 0.0f;
	}
}