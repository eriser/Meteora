#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class TriangleWave : public IGenerator
	{
	public:
		TriangleWave();
		~TriangleWave();

		virtual const Sound generateSound(const Phase phase) override;
	};

}