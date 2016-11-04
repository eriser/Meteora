#pragma once
#include "../models/MeteoraTypes.h"

namespace Meteora
{
	class IModule
	{
	public:
		virtual ~IModule() {}
		IModule() {}

	protected:
		Frequency samplingFrequency;

	private:
	};
}