#pragma once
#include <stdint.h>

/**
	20/10/2016	MeteoraTypes.h
	This file defines the basic type for the Meteora Synth.
*/

namespace Meteora
{
	using SoundSample_32 = int32_t;	// value sampled at 32 bits
	using SoundSample_16 = int16_t;	// value sampled at 16 bits
	using Sound = double;			// sound to be sampled
	using Duration = uint32_t;		// milliseconds
	using Octave = uint8_t;			// octave
	using Pitch = double;			// pitch
	using Gate = bool;				// gate
	using Voltage = double;			// output voltage of a module
	using Note = uint8_t;			// note
	using Frequency = double;		// frequency
	using Time = double;			// time (typically in seconds)
	using Phase = double;			// phase
}