#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class SquareWave : public IGenerator
	{
	public:
		SquareWave();
		~SquareWave();

		virtual const float generateSound(const float phase) override;
	};
}