#pragma once
#include "IGenerator.h"
#include <chrono>
#include <random>

namespace Meteora {

	class WhiteNoise : public IGenerator
	{
	public:
		WhiteNoise();
		virtual ~WhiteNoise();

		virtual const Sound generateSound(const Phase phase = 0) override;

	protected:
		void initRandomGenerator();
		std::normal_distribution<float> distribution;
		std::default_random_engine generator;
	};
}