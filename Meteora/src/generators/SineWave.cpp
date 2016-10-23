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

	std::vector<SoundSample> SineWave::generateSound(uint32_t samplingFrequency, float frequency, Duration duration, float volume)
	{
		// number of samples that the buffer contains
		int64_t nSamples = samplingFrequency * duration / 1000.0;

		// create the return vector, filled with a size of nSamples with value = 0
		std::vector<SoundSample> buffer(nSamples, 0);

		// generate the sine wave only if the frequency is > 0
		if ( frequency > 0.0 )
		{
			// increase of step for each period of time: y = A * sin(2*pi*omega*dt)
			double phaseStep = M_TWOPI / (double)samplingFrequency * frequency;

			// phase value used in the loop to populate the buffer. The value 0 is arbitrary
			double phase = 0;

			const SoundSample MaxValue = std::numeric_limits<SoundSample>::max();

			// build the signal
			for (auto& value : buffer)
			{
				value = volume * MaxValue *sin(phase);
				phase += phaseStep;

				// reset the phase for the next step if this exceeds 2 PI
				// [AR] is this step really necessary?
				if (phase > M_TWOPI)
				{
					phase -= M_TWOPI;
				}
			}
		}

		return buffer;
	}

}