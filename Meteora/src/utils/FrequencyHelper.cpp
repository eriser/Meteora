#include "FrequencyHelper.h"
#include "MeteoraDefs.h"
#include <cmath>

namespace Meteora
{
	const Frequency FrequencyHelper::calculateFrequency(const Octave octave, const Pitch pitch)
	{
		Frequency ret = 0.0;

		if (isValidOctave(octave) && isValidPitch(pitch))
		{
			ret = M_A4_NOTE * pow(2, calculateNotePosition(octave, 1) + pitch - M_A4_NOTE_POS);
		}

		return ret;
	}

	const Frequency FrequencyHelper::calculateFrequency(const Octave octave, const Note note)
	{
		Frequency ret = 0.0;

		if (isValidOctave(octave) && isValidNoteInOctave(note))
		{
			auto asd = calculateNotePosition(octave, note) - M_A4_NOTE_POS;
			ret = M_A4_NOTE * pow(M_TEMPERED_NOTE_RATIO, calculateNotePosition(octave, note) - M_A4_NOTE_POS);
		}

		return ret;
	}

	const bool FrequencyHelper::isValidOctave(const Octave octave)
	{
		return (octave >= 0 && octave <= 10);
	}

	const bool FrequencyHelper::isValidPitch(const Pitch pitch)
	{
		return (pitch >= 0.0f && pitch <= 1.0);
	}

	const bool FrequencyHelper::isValidNoteInOctave(const Note note)
	{
		return (note >= 1 && note <= 12);
	}

	const int FrequencyHelper::calculateNotePosition(const Octave octave, const Note note)
	{
		return octave * 12 + note;
	}


	FrequencyHelper::FrequencyHelper()
	{
	}

	FrequencyHelper::~FrequencyHelper()
	{
	}

}