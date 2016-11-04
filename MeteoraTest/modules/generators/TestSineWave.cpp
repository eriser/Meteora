#include "stdafx.h"
#include "CppUnitTest.h"
#include <modules/generators/IGenerator.h>
#include <modules/generators/SineWave.h>

#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Meteora;

namespace MeteoraTest
{		
	TEST_CLASS(Test_SineWave)
	{
	public:
		
		TEST_METHOD(Test_SineWave_GenerateSound_Inputs_Zero)
		{
			// create a new SineWave generator
			SineWave sineGenerator = SineWave();

			// try to generate a sound with negative frequency
			auto retSound = sineGenerator.generateSound(0);
			
			// they must be 0.
			Assert::AreEqual(retSound, 0.0);
		}

		TEST_METHOD(Test_SineWave_GenerateSound_Inputs_Max_Value)
		{
			SineWave sineGenerator = SineWave();
			auto value = sineGenerator.generateSound(M_HALFPI);
			// ensure that the quality is pretty high
			Assert::IsTrue(value <= 1.0 && value >= 0.99999);
		}
	};
}