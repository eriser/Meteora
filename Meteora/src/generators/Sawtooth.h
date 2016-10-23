#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class Sawtooth : public IGenerator
	{
	public:
		Sawtooth();
		~Sawtooth();

		virtual const float generateSound(const float phase) override;
	};

}