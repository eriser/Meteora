#include "VoltageControlledOscillator.h"
#include "../generators/SineWave.h"
#include "../../utils/FrequencyHelper.h"

namespace Meteora
{
	/// <summary> Secondary constructor, initialized with a SineWave oscillator </summary>
	VoltageControlledOscillator::VoltageControlledOscillator() :
		VoltageControlledOscillator(std::make_shared<SineWave>())
	{
	}

	/// <summary> Main VoltageControlledOscillator class constructor </summary>
	/// <param name="generator">Shared pointer containing the chosen type of generator</param>
	/// <param name="octave"> The octave of the sound </param>
	/// <param name="pitch"> The pitch of the sound to generate, following the 1V/Octave standard </param>
	VoltageControlledOscillator::VoltageControlledOscillator(std::shared_ptr<IGenerator> generator, Octave octave, Pitch pitch)
	{
		this->generator = generator;
		this->octave = octave;
		this->pitch = pitch;
		this->phase = .0;
		this->frequency = FrequencyHelper::calculateFrequency(octave, pitch);
	}

	/// <summary> Destructor </summary>
	VoltageControlledOscillator::~VoltageControlledOscillator()
	{
	}

	/// <summary> Calculate the output value for the oscillator at a given time </summary>
	/// <param name="time"> Time in seconds</param>
	const Voltage VoltageControlledOscillator::output(const Time time)
	{
		return output(time, this->generator);
	}

	/// <summary>	Calculate the output for a given generator at a given time. This method could be
	///				redundant considering the other output method However this could be useful when
	///				the output for multiple generators is needed at the same time.
	/// </summary>
	///
	const Voltage VoltageControlledOscillator::output(const Time time, std::shared_ptr<IGenerator> generator)
	{
		Voltage ret = .0;

		if (generator != nullptr)
		{
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
			this->frequency = FrequencyHelper::calculateFrequency(octave, pitch);
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
			this->frequency = FrequencyHelper::calculateFrequency(octave, pitch);
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

	const Frequency VoltageControlledOscillator::getFrequency() const
	{
		return frequency;
	}

}