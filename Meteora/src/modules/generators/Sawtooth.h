#pragma once
#include "IGenerator.h"

namespace Meteora
{
	class Sawtooth : public IGenerator
	{
	public:
		Sawtooth();
		~Sawtooth();

		virtual const Phase generateSound(const Phase phase) override;
	};

}