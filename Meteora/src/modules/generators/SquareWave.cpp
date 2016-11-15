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
		return phase >= M_PI ? 1.0 : 0.0;
	}
}