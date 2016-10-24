#pragma once
#include "../models/MeteoraTypes.h"


namespace Meteora
{

	class FrequencyHelper
	{
	public:
		static const Frequency calculateFrequency(const Octave octave, const Pitch pitch);
		static const Frequency calculateFrequency(const Octave octave, const Note note);
		static const bool isValidOctave(const Octave octave);
		static const bool isValidPitch(const Pitch pitch);
		static const bool isValidNoteInOctave(const Note note);
		static const int FrequencyHelper::calculateNotePosition(const Octave octave, const Note note);

	private:
		FrequencyHelper();
		~FrequencyHelper();
	};

}