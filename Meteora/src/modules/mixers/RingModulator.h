#pragma once

namespace Meteora
{
	class RingModulator
	{
	public:
		RingModulator();
		~RingModulator();
		const float computeOutput(const float signalA, const float signalB) const;
	};

}