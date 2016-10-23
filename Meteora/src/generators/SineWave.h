#pragma once
#include "IGenerator.h"
#include <vector>

namespace Meteora
{
	class SineWave : public IGenerator
	{
	public:
		SineWave();
		~SineWave();

		virtual std::vector<SoundSample> generateSound(uint32_t samplingFrequency, float frequency, Duration duration, float volume) override;
	};

}