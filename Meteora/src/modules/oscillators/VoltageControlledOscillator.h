#pragma once
#include <memory>
#include "../../models/MeteoraTypes.h"
#include "../generators/IGenerator.h"
#include "../IModule.h"
#include "../../utils/MeteoraDefs.h"

namespace Meteora
{
	class VoltageControlledOscillator : public IModule
	{
	public:
#pragma region Constructor
		VoltageControlledOscillator();
		VoltageControlledOscillator(std::shared_ptr<IGenerator> generator,  Octave octave = .0f, Pitch pitch = .0, Frequency samplingFrequency = DEFAULT_SAMPLNG_FREQUENCY);
		~VoltageControlledOscillator();
#pragma endregion

#pragma region Methods
		const Voltage output();
		const Voltage output(std::shared_ptr<IGenerator> generator);
#pragma endregion

#pragma region Getters and Setters
		const Octave getOctave() const;
		void setOctave(const Octave octave);

		const Pitch getPitch() const;
		void setPitch(const Pitch pitch);

		const std::shared_ptr<IGenerator> getGenerator() const;
		void setGenerator(const std::shared_ptr<IGenerator>);

		const Frequency getFrequency() const;
#pragma endregion


	protected:
#pragma region Fields
		Octave octave;
		Pitch pitch;	// the pitch follows the 1V / Octave convention
		Frequency frequency;
		Phase phase;
		std::shared_ptr<IGenerator> generator;

	private:
		Time oneOverSamplingFrequency;
#pragma endregion
	};

	// Simplify typename using an alias
	using VCO = VoltageControlledOscillator;

}