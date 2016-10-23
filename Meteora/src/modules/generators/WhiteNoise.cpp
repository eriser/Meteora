#include "WhiteNoise.h"

namespace Meteora
{

	WhiteNoise::WhiteNoise()
	{
		// init when the generator is created
		initRandomGenerator();
	}


	WhiteNoise::~WhiteNoise()
	{
	}

	// use the standard normal distribution to generate gaussian white noise
	const float WhiteNoise::generateSound(const float phase)
	{
		return distribution(generator);
	}

	void WhiteNoise::initRandomGenerator()
	{
		// construct a trivial random generator engine from a time-based seed:
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		distribution = std::normal_distribution<float>(0.0, 1.0);
	}

} // namespace Meteora