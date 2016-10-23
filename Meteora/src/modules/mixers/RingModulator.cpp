#include "RingModulator.h"

namespace Meteora
{

	RingModulator::RingModulator()
	{
	}


	RingModulator::~RingModulator()
	{
	}

	const float Meteora::RingModulator::computeOutput(const float signalA, const float signalB) const
	{
		return signalA * signalB;
	}

}