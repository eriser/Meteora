#pragma once
#include "../../models/MeteoraTypes.h"
#include "../../utils/MeteoraDefs.h"

/**
	20/10/2016 IGenerator.h

	This is the basic interface for all the Meteora generators, defining the base behaviour.
*/

namespace Meteora
{
	class IGenerator
	{
	public:
		virtual ~IGenerator();
		virtual const Sound generateSound(const Phase phase) = 0;
	protected:
		IGenerator();
	};
}