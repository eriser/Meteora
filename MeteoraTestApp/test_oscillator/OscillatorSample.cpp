#include "stdafx.h"
#include "OscillatorSample.h"
#include "src\utils\MeteoraDefs.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <iomanip>

OscillatorSample::OscillatorSample() : error(Pa_Initialize())
{
	vco = VCO(std::make_shared<SineWave>(), 4, 0.12);
	env.setAttack(.1 * DEFAULT_SAMPLING_FREQUENCY);
	env.setDecay(0.1 * DEFAULT_SAMPLING_FREQUENCY);
	env.setSustain(.3);
	env.setRelease(2 * DEFAULT_SAMPLING_FREQUENCY);
	left_phase = 0.0;
	right_phase = 0.0;
	
	generators.push_back(std::make_shared<SineWave>());
	generators.push_back(std::make_shared<SquareWave>());
	generators.push_back(std::make_shared<TriangleWave>());
	generators.push_back(std::make_shared<WhiteNoise>());

	gen = 0;
}

OscillatorSample::~OscillatorSample()
{
	if (error != paNoError)
	{
		Pa_Terminate();
	}
}

void OscillatorSample::performSample()
{
	init();
	play();
	char c = 'a';
	double amount = 1.2;
	int sleepMs = 100;
	system("cls");
	updateScreen();

	do
	{
		//c = _getch();

		if (GetAsyncKeyState('G') & 0x8000)
		{
			env.setGate(true);
		}
		else
		{
			env.setGate(false);
		}

		if (GetAsyncKeyState('T') & 0x8000)
		{
			vco.setGenerator(generators[(++gen)%generators.size()]);
			updateScreen();
			Pa_Sleep(sleepMs * 10);
		}

		if (GetAsyncKeyState('Y') & 0x8000)
		{
			env.setAttack(env.getAttack() * amount);
			Pa_Sleep(sleepMs);
			updateScreen();
		}
		if (GetAsyncKeyState('H') & 0x8000)
		{
			env.setAttack(env.getAttack() / amount);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('U') & 0x8000)
		{
			env.setDecay(env.getDecay() * amount);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('J') & 0x8000)
		{
			env.setDecay(env.getDecay() / amount);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('O') & 0x8000)
		{
			env.setRelease(env.getRelease() * amount);
			updateScreen();
			Pa_Sleep(sleepMs);
		}
		if (GetAsyncKeyState('L') & 0x8000)
		{
			env.setRelease(env.getRelease() / amount);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('I') & 0x8000)
		{
			env.setSustain(env.getSustain() + 0.1);
			updateScreen();
			Pa_Sleep(sleepMs);
		}
		if (GetAsyncKeyState('K') & 0x8000)
		{
			env.setSustain(env.getSustain() - 0.1);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('Q') & 0x8000)
		{
			vco.setOctave(vco.getOctave() + 1);
			updateScreen();
			Pa_Sleep(sleepMs);
		}
		else if (GetAsyncKeyState('A') & 0x8000)
		{
			vco.setOctave(vco.getOctave() - 1);
			updateScreen();
			Pa_Sleep(sleepMs);
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			if (vco.getPitch() >= 11.0 / 12.0)
			{
				vco.setOctave(vco.getOctave() + 1);
				vco.setPitch(0);
			}
			else
			{
				vco.setPitch(vco.getPitch() + 1/12.0);
			}
			updateScreen();
			Pa_Sleep(sleepMs);
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{

			if (vco.getPitch() < 1.0 / 12.0 && vco.getOctave() != 0)
			{
				vco.setOctave(vco.getOctave() - 1);
				vco.setPitch(1);
			}
			else
			{
				vco.setPitch(vco.getPitch() - 1/12.0);
			}

			updateScreen();
			Pa_Sleep(sleepMs);
		}

	}while (!(GetAsyncKeyState('E') & 0x8000));
	stop();
	close();
}


PaError OscillatorSample::getError() const
{
	return error;
}

void OscillatorSample::init()
{
	PaStreamParameters outputParameters;

	auto index = Pa_GetDefaultOutputDevice();
	outputParameters.device = index;

	if (outputParameters.device == paNoDevice) {
		return;
	}

	const PaDeviceInfo* pInfo = Pa_GetDeviceInfo(index);
	if (pInfo != 0)
	{
		printf("Output device name: '%s'\r", pInfo->name);
	}

	outputParameters.channelCount = 2;       /* stereo output */
	outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
	outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
	outputParameters.hostApiSpecificStreamInfo = NULL;

	PaError err = Pa_OpenStream(
		&stream,
		NULL, /* no input */
		&outputParameters,
		DEFAULT_SAMPLING_FREQUENCY,
		framesPerBuffer,
		paClipOff,      /* we won't output out of range samples so don't bother clipping them */
		paCallback,
		this            /* Using 'this' for userData so we can cast to Sine* in paCallback method */
	);

	if (err != paNoError)
	{
		/* Failed to open stream to device !!! */
		return;
	}

	err = Pa_SetStreamFinishedCallback(stream, paStreamFinished);

	if (err != paNoError)
	{
		Pa_CloseStream(stream);
		stream = 0;

		return;
	}

}

void OscillatorSample::play()
{
	if (stream == 0)
		return;

	Pa_StartStream(stream);
}

void OscillatorSample::stop()
{
	if (stream == 0)
		return;

	Pa_StopStream(stream);
}

void OscillatorSample::close()
{
	if (stream == 0)
		return;

	Pa_CloseStream(stream);
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

void OscillatorSample::updateScreen()
{
	int n_rows = 15;
	gotoxy(0, 0);

	for (int i = 0; i < n_rows; i++)
	{
		std::cout << std::string("\n") << std::endl;
	}

	gotoxy(0, 0);

	printf("Octave:\t\t%d\n", vco.getOctave());
	printf("Pitch:\t\t%.3f\n", vco.getPitch());
	printf("Frequency:\t%.3f\n", vco.getFrequency());
	printf("Attack:\t\t%.3f\n", env.getAttack());
	printf("Decay:\t\t%.3f\n", env.getDecay());
	printf("Sustain:\t%.3f\n", env.getSustain());
	printf("Release:\t%.3f\n", env.getRelease());
}

int OscillatorSample::paCallback(const void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo * timeInfo, PaStreamCallbackFlags statusFlags, void * userData)
{
	return static_cast<OscillatorSample*>(userData)->callback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);
}

int OscillatorSample::callback(const void * inputBuffer, void * outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo * timeInfo, PaStreamCallbackFlags statusFlags)
{
	float *out = (float*)outputBuffer;
	unsigned long i;

	(void)timeInfo; /* Prevent unused variable warnings. */
	(void)statusFlags;
	(void)inputBuffer;
	auto min_t = 1.0 / DEFAULT_SAMPLING_FREQUENCY;

	for (i = 0; i<framesPerBuffer; i++)
	{
		left_phase += min_t;
		auto value = vco.output() *env.output();
		*out++ = value;
		*out++ = value;
	}

	return paContinue;
}

void OscillatorSample::paStreamFinished(void * userData)
{
	return static_cast<OscillatorSample*>(userData)->streamFinished();
}

void OscillatorSample::streamFinished()
{
}
