#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class SineWave : public IGenerator
	{
	public:
		SineWave();
		virtual ~SineWave();

		virtual const float generateSound(const float phase) override;
	};

}