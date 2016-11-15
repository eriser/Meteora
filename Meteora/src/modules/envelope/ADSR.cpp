#include "ADSR.h"
#include <math.h>
#include "../../utils/MeteoraDefs.h"

namespace Meteora
{
	const double ADSR::targetRatioAttack = 0.3;
	const double ADSR::targetRatioDecayRelease = 0.0001;

	ADSR::ADSR() : ADSR(0, 0, 1, 0)
	{
	}

	ADSR::ADSR(const double attack, const double decay, const double sustain, const double release)
	{
		setAttack(attack);
		setDecay(decay);
		setSustain(sustain);
		setRelease(release);
		state = env_idle;
		_output = 0;
	}


	ADSR::~ADSR()
	{
	}

#pragma region Getters and Setters
	const double ADSR::getAttack() const
	{
		return attackRate;
	}

	const double ADSR::getDecay() const
	{
		return decayRate;
	}

	const double ADSR::getSustain() const
	{
		return sustainLevel;
	}

	const double ADSR::getRelease() const
	{
		return releaseRate;
	}

	void ADSR::setAttack(const double attack)
	{
		attackRate = attack;
		attackCoefficient = calcCoef(attackRate, targetRatioAttack);
		attackBase = (1.0 + targetRatioAttack) * (1.0 - attackCoefficient);
	}

	void ADSR::setDecay(const double decay)
	{
		decayRate = decay;
		decayCoefficient = calcCoef(decayRate, targetRatioDecayRelease);
		decayBase = (sustainLevel - targetRatioDecayRelease) * (1.0 - decayCoefficient);
	}

	void ADSR::setSustain(const double sustain)
	{
		sustainLevel = sustain;
		decayBase = (sustainLevel - targetRatioDecayRelease) * (1.0 - decayCoefficient);
	}

	void ADSR::setRelease(const double release)
	{
		this->releaseRate = release;
		releaseCoefficient = calcCoef(releaseRate, targetRatioDecayRelease);
		releaseBase = -targetRatioDecayRelease * (1.0 - releaseCoefficient);
	}

	const bool ADSR::getGate() const
	{
		return gate;
	}

	void ADSR::setGate(const bool gate)
	{
		if (gate)
		{
			state = env_attack;
		}
		else if (state != env_idle)
		{
			state = env_release;
		}
	}

#pragma endregion
	double ADSR::calcCoef(double rate, double targetRatio)
	{
		return exp(-log((1.0 + targetRatio) / targetRatio) / rate);
	}

	void ADSR::process()
	{
		switch (state)
		{
			case env_idle:
				break;
			case env_attack:
				_output = attackBase + _output * attackCoefficient;
				if (_output >= 1.0) {
					_output = 1.0;
					state = env_decay;
				}
				break;
			case env_decay:
				_output = decayBase + _output * decayCoefficient;
				if (_output <= sustainLevel) {
					_output = sustainLevel;
					state = env_sustain;
				}
				break;
			case env_sustain:
				break;
			case env_release:
				_output = releaseBase + _output * releaseCoefficient;
				if (_output <= 0.0001) {
					_output = 0.0;
					state = env_idle;
				}
		}
	}

	const double ADSR::output()
	{
		process();
		return _output;
	}
}