#pragma once
#include "IGenerator.h"
#include "../../utils/MeteoraDefs.h"
#include "../../utils/MathUtils.h"

#define SINE_TABLE_SIZE 4096


namespace Meteora
{
	class SineWave : public IGenerator
	{
	public:
		SineWave();
		virtual ~SineWave();

		virtual const Sound generateSound(const Phase phase) override;
	private:
		static double sineTable[4096];

		inline double Hill(double x)
		{
			const double a0 = 1.0;
			const double a2 = 2.0 / M_PI - 12.0 / (M_PI * M_PI);
			const double a3 = 16.0 / (M_PI * M_PI * M_PI) - 4.0 / (M_PI * M_PI);
			const double xx = x * x;
			const double xxx = xx * x;

			return a0 + a2 * xx + a3 * xxx;
		}

		double FastSin(double x)
		{
			x = MathUtils::wrapTwoPI(x);

			// 4 pieces of hills
			if (x < M_HALFPI)
				return Hill(M_HALFPI - x);
			else if (x < M_PI)
				return Hill(x - M_HALFPI);
			else if (x < 3.0 * M_HALFPI)
				return -Hill(3.0 * M_HALFPI - x);
			else
				return -Hill(x - 3.0 * M_HALFPI);
		}
	};

}