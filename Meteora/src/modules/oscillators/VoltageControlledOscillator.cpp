#include "VoltageControlledOscillator.h"
#include "../generators/SineWave.h"

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
		this->phase = .0f;
	}


	VoltageControlledOscillator::~VoltageControlledOscillator()
	{
	}

	const Voltage VoltageControlledOscillator::output()
	{
		Voltage ret = .0f;

		//float frequency = 

		return ret;
	}

	const Octave VoltageControlledOscillator::getOctave() const
	{
		return octave;
	}

	void VoltageControlledOscillator::setOctave(const Octave octave)
	{
		if ( octave >= 0 && octave <= 10 )
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
		if (pitch >= 0 && pitch <= 1)
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