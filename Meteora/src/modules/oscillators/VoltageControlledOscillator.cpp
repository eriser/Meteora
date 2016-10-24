#include "VoltageControlledOscillator.h"
#include "../generators/SineWave.h"
#include "../../utils/FrequencyHelper.h"

namespace Meteora
{
	VoltageControlledOscillator::VoltageControlledOscillator() :
		VoltageControlledOscillator(std::make_shared<SineWave>())
	{
	}

	VoltageControlledOscillator::VoltageControlledOscillator(std::shared_ptr<IGenerator> generator, Octave octave, Pitch pitch)
	{
		this->generator = generator;
		this->octave = octave;
		this->pitch = pitch;
		this->phase = .0;
	}


	VoltageControlledOscillator::~VoltageControlledOscillator()
	{
	}

	const Voltage VoltageControlledOscillator::output(const float time) const
	{
		return output(time, this->generator);
	}

	const Voltage VoltageControlledOscillator::output(const float time, std::shared_ptr<IGenerator> generator) const
	{
		Voltage ret = .0;

		if (generator != nullptr)
		{
			float frequency = FrequencyHelper::calculateFrequency(octave, pitch);
			ret = generator->generateSound(M_TWOPI * frequency * time);
		}

		return ret;
	}

	const Octave VoltageControlledOscillator::getOctave() const
	{
		return octave;
	}

	void VoltageControlledOscillator::setOctave(const Octave octave)
	{
		if ( FrequencyHelper::isValidOctave(octave) )
		{
			this->octave = octave;
		}
	}

	const Pitch VoltageControlledOscillator::getPitch() const
	{
		return pitch;
	}

	void VoltageControlledOscillator::setPitch(const Pitch pitch)
	{
		if ( FrequencyHelper::isValidPitch(pitch) )
		{
			this->pitch = pitch;
		}
	}

	const std::shared_ptr<IGenerator> VoltageControlledOscillator::getGenerator() const
	{
		return generator;
	}

	void VoltageControlledOscillator::setGenerator(const std::shared_ptr<IGenerator> generator)
	{
		if (generator != nullptr)
		{
			this->generator = generator;
		}
	}

}