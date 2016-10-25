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

		 
		///	<summary> Check that the calculated frequency for the lowest note is correct
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Note_C0)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 0 }, Note{ Notes::C }), M_C0_NOTE, M_NOTE_FREQ_TOLERANCE);
		}

		/// <summary> Check that the frequency for the note is correct in the upper octave </summary>
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Note_C1)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 1 }, Note{ Notes::C }), M_C0_NOTE * 2, M_NOTE_FREQ_TOLERANCE);
		}

		/// <summary> Check frequency of A4 = 440Hz note. </summary>
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Note_A4)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Note{ Notes::A }), M_A4_NOTE, M_NOTE_FREQ_TOLERANCE);
		}

		/// <summary> Check the correspondence between the pitch and the note at the beginning of the interval
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_Begin)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Pitch{ 0 }), FrequencyHelper::calculateFrequency(Octave{ 4 }, Note{ 1 }), M_NOTE_FREQ_TOLERANCE);
		}

		/// <summary> Check the correspondence between the pitch and the note at the end of the interval
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_End)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Pitch{ 1 }), FrequencyHelper::calculateFrequency(Octave{ 5 }, Note{ 1 }), M_NOTE_FREQ_TOLERANCE);
		}
		
		/// <summary> Check the pitch and the note for the first semitone
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_FirstSemi)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Pitch{ 1.0 / 12.0 }), FrequencyHelper::calculateFrequency(Octave{ 4 }, Note{ 2 }), M_NOTE_FREQ_TOLERANCE);
		}
		
		/// <summary> Check the pitch and the note in the middle of the scale
		TEST_METHOD(Test_FrequencyHelper_CalcFreq_Pitch_Mid)
		{
			Assert::AreEqual(FrequencyHelper::calculateFrequency(Octave{ 4 }, Pitch{ 6.0 / 12.0 }), FrequencyHelper::calculateFrequency(Octave{ 4 }, Note{ 7 }), M_NOTE_FREQ_TOLERANCE);
		}
	};
}