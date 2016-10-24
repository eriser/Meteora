#pragma once
#include <stdint.h>

/**
	20/10/2016	MeteoraTypes.h
	This file defines the basic type for the Meteora Synth.
*/

namespace Meteora
{
	using SoundSample = int32_t;	// value sampled at 32 bits
	using Duration = uint32_t;		// milliseconds
	using Octave = uint16_t;		// octave
	using Pitch = float;			// pitch
	using Gate = bool;				// gate
	using Voltage = float;			// output voltage of a module
}