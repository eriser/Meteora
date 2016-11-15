#pragma once
/**
	20/10/2016 MeteoraDefs.h

	This file includes the basic definitions for the Meteora Synth
*/

#ifndef M_PI
#define M_PI 3.14159265359
#endif

#ifndef M_2PI
#define M_TWOPI 6.28318530718
#endif

#ifndef M_ONE_OVER_TWOPI
#define M_ONE_OVER_TWOPI 0.1591549430919
#endif

#ifndef M_HALFPI
#define M_HALFPI 1.57079632679
#endif

#ifndef M_QUARTERPI
#define M_QUARTPI 0.78539816339
#endif

#ifndef M_A4_NOTE
#define M_A4_NOTE 440.0
#endif

#ifndef M_A4_NOTE_POS
#define M_A4_NOTE_POS 58
#endif

#ifndef M_C0_NOTE
#define M_C0_NOTE 16.35
#endif

#ifndef M_TEMPERED_NOTE_RATIO
#define M_TEMPERED_NOTE_RATIO 1.0594630943592952645618252949463
#endif

#ifndef M_NOTE_FREQ_TOLERANCE
#define M_NOTE_FREQ_TOLERANCE 0.01
#endif

#ifndef DEFAULT_SAMPLING_FREQUENCY
#define DEFAULT_SAMPLING_FREQUENCY 44100.0
#endif

namespace Meteora
{
	enum Notes
	{
		C = 1,		// 1
		C_d,		// 2
		D_b = C_d,
		D,			// 3
		D_d,		// 4
		E_b = D_d,
		E,			// 5
		F,			// 6
		F_d,		// 7
		G_b = F_d,
		G,			// 8
		G_d,		// 9
		A_b = G_d,
		A,			// 10
		A_d,		// 11
		B_b = A_d,
		B			// 12
	};
}