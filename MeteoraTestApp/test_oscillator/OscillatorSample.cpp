#include "stdafx.h"
#include "OscillatorSample.h"
#include "src\utils\MeteoraDefs.h"
#include <conio.h>

OscillatorSample::OscillatorSample() : error(Pa_Initialize())
{
	vco = VCO(std::make_shared<SineWave>(), 4, 0.12);
	left_phase = 0.0;
	right_phase = 0.0;
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
	char c;
	do
	{
		c = _getch();
		if (c == 'q') vco.setOctave(vco.getOctave() + 1);
		else if (c == 'a') vco.setOctave(vco.getOctave() - 1);

		if (c == 'w')
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
		}
		else if (c == 's') 
		{

			if (vco.getPitch() <= 1.0 / 12.0)
			{
				vco.setOctave(vco.getOctave() - 1);
				vco.setPitch(1);
			}
			else
			{
				vco.setPitch(vco.getPitch() - 1/12.0);
			}
		}

	}while (c != 'e');
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
		DEFAULT_SAMPLNG_FREQUENCY,
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
	auto min_t = 1.0 / DEFAULT_SAMPLNG_FREQUENCY;

	for (i = 0; i<framesPerBuffer; i++)
	{
		left_phase += min_t;
		auto value = vco.output();
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
