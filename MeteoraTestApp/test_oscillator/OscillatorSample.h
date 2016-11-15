#pragma once
#include "portaudio.h"
#include "modules\oscillators\VoltageControlledOscillator.h"
#include "modules\generators\Sawtooth.h"
#include "modules\generators\SineWave.h"
#include "modules\generators\SquareWave.h"
#include "modules\generators\TriangleWave.h"
#include "modules\generators\WhiteNoise.h"
#include "modules\envelope\ADSR.h"
#include <vector>

using namespace Meteora;

class OscillatorSample
{
public:
	OscillatorSample();
	~OscillatorSample();
	void performSample();
	PaError getError() const;

protected:
	PaError error;

	void init();
	void play();
	void stop();
	void close();

	void updateScreen();

	static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
	int callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags);

	static void paStreamFinished(void* userData);
	void streamFinished();

	PaStream *stream;
	double left_phase;
	double right_phase;
	VCO vco;
	ADSR env;
	std::vector<std::shared_ptr<IGenerator>> generators;
	int gen;

	const int framesPerBuffer = paFramesPerBufferUnspecified;
	bool gate;
};