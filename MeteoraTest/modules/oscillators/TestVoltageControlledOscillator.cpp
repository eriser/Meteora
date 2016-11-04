#include "stdafx.h"
#include "CppUnitTest.h"
#include <utils/MeteoraDefs.h>
#include <modules/oscillators/VoltageControlledOscillator.h>
#include <modules/generators/SineWave.h>

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Meteora;

namespace MeteoraTest
{
	TEST_CLASS(Test_VoltageControlledOscillator)
	{
	public:

		TEST_METHOD(Test_VCO_Sine)
		{
			Frequency samplingFreq = DEFAULT_SAMPLNG_FREQUENCY;
			Time duration = .02;
			// create a new VCO using a sine wave generator
			VCO vco = VCO(std::make_shared<SineWave>(), samplingFreq, 4, 9 / 12.0);

			std::ofstream file("VCO_Sine.csv");

			for (Time time = 0.0; time < duration; time += 1.0 / samplingFreq)
			{
				file << time << ";" << vco.output(time) << std::endl;
			}

			file.close();
		}
	};
}