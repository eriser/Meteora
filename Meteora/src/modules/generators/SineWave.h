#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class SineWave : public IGenerator
	{
	public:
		SineWave();
		virtual ~SineWave();

		virtual const Sound generateSound(const Phase phase) override;
	};

}