#pragma once
#include "IGenerator.h"
#include <vector>

namespace Meteora
{
	class SineWave : public IGenerator
	{
	public:
		SineWave();
		~SineWave();

		virtual float generateSound(float phase) override;
	};

}