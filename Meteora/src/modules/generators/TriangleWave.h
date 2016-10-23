#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class TriangleWave : public IGenerator
	{
	public:
		TriangleWave();
		~TriangleWave();

		virtual const float generateSound(const float phase) override;
	};

}