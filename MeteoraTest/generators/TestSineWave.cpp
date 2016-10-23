#include "stdafx.h"
#include "CppUnitTest.h"
#include <generators/IGenerator.h>
#include <generators/SineWave.h>

#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Meteora;

namespace MeteoraTest
{		
	TEST_CLASS(Test_SineWave)
	{
	public:
		
		TEST_METHOD(Test_SineWave_GenerateSound_Inputs)
		{
			// create a new SineWave generator
			SineWave sineGenerator = SineWave();

			// try to generate a sound with negative frequency
			auto retSound = sineGenerator.generateSound(44100, -1, 1000, 1);
			
			// look up for non zeroes elements
			int numberOfNotZeroes = std::count_if(retSound.begin(), retSound.end(), [](SoundSample x) { return x != 0; });

			// they must be 0.
			Assert::AreEqual(numberOfNotZeroes, 0);
		}

		TEST_METHOD(Test_SineWave_GenerateSound_Range)
		{
			// create a new SineWave generator
			SineWave sineGenerator = SineWave();
			const double MaxFreq = 200;
			const double IncFreq = 25;

			// generate a sine wave
			for (double sweepFreq = 50; sweepFreq < MaxFreq; sweepFreq += IncFreq)
			{
				// generate a sine wave with 1000 ms length
				auto res = sineGenerator.generateSound(44100, sweepFreq, 1000, 1);

				// the number of samples generated shall be the same
				Assert::AreEqual(res.size(), (size_t)44100 * 1);
			}
		}
	};
}