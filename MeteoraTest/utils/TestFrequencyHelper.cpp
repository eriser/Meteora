#include "stdafx.h"
#include "CppUnitTest.h"
#include <utils/FrequencyHelper.h>
#include <utils/MeteoraDefs.h>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Meteora;

namespace MeteoraTest
{
	TEST_CLASS(Test_FrequencyHelper)
	{
	public:

		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_C0)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 0 }, Note{ Notes::C }), M_C0_NOTE, M_NOTE_FREQ_TOLERANCE);
		}


		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_C1)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 1 }, Note{ Notes::C }), M_C0_NOTE * 2, M_NOTE_FREQ_TOLERANCE);
		}


		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_A4)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Note{ Notes::A }), M_A4_NOTE, M_NOTE_FREQ_TOLERANCE);
		}
	};
}