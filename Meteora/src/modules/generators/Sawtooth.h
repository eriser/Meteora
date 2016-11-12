#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class Sawtooth : public IGenerator
	{
	public:
		Sawtooth();
		~Sawtooth();

		virtual const Sound generateSound(const Phase phase) override;
	};

}