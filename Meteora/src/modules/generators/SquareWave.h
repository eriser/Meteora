#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class SquareWave : public IGenerator
	{
	public:
		SquareWave();
		~SquareWave();

		virtual const Sound generateSound(const Phase phase) override;
	};
}