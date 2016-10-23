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
}