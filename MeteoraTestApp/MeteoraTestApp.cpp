// MeteoraTestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <modules/generators/SineWave.h>
#include <modules/oscillators/VoltageControlledOscillator.h>
#include <thirdparty/fmod/fmod.hpp>

using namespace Meteora;

int main()
{
	FMOD::System* system;
	if (FMOD::System_Create(&system) != FMOD_OK)
	{
		// Report Error
		return 1;
	}

	int driverCount = 0;
	system->getNumDrivers(&driverCount);

	if (driverCount == 0)
	{
		// Report Error
		return 1;
	}

	// Initialize our Instance with 36 Channels
	system->init(36, FMOD_INIT_NORMAL, NULL);

	VoltageControlledOscillator oscillator(std::make_shared<SineWave>(), 4, 9 / 12.0);
	
	std::cout << "Frequency = "<< oscillator.getFrequency() << " [Hz]"<< std::endl;

	for (double time = 0.0; time < 1; time += 0.0001)
	{
		std::cout << std::setprecision(6) << "Val = " << oscillator.output(time)
			<< "\t t = " << time << " [s]" << std::endl;
	}

	std::cin.get();

	return 0;
}

