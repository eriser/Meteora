#include "SineWave.h"
#include <cmath>
#include <limits>

namespace Meteora
{
	SineWave::SineWave()
	{
	}


	SineWave::~SineWave()
	{
	}

	float SineWave::generateSound(float phase)
	{
		// let the control on the volume, frequency, amplitude and sampling frequency be external.
		return sin(phase);
	}

}