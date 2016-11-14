#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include "test_oscillator/OscillatorSample.h"

int main(int argc, char** argv)
{
	OscillatorSample sample = OscillatorSample();
	
	if (sample.getError() == paNoError)
	{
		sample.performSample();
	}

	return 0;
}