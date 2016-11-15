#pragma once
#include "../IModule.h"

namespace Meteora
{
	class ADSR : IModule
	{
	public:
		ADSR();
		ADSR(const double attack, const double decay, const double sustain, const double release);
		~ADSR();

#pragma region Getters and Setters
		const double getAttack() const;
		const double getDecay() const;
		const double getSustain() const;
		const double getRelease() const;

		void setAttack(const double attack);
		void setDecay(const double decay);
		void setSustain(const double sustain);
		void setRelease(const double release);

		const bool getGate() const;
		void setGate(const bool gate);		
#pragma endregion

		const double output();

	protected:
		double attackRate;
		double attackBase;
		double attackCoefficient;
		double decayRate;
		double decayBase;
		double decayCoefficient;
		double sustainLevel;

		double releaseRate;
		double releaseBase;
		double releaseCoefficient;
		bool gate;

		double _output;

		static const double targetRatioAttack;
		static const double targetRatioDecayRelease;

		double calcCoef(double rate, double targetRatio);
		void process();

		typedef enum EnvelopeStatus
		{
			env_idle,
			env_attack,
			env_decay,
			env_sustain,
			env_release
		};

		EnvelopeStatus state;
	};

}