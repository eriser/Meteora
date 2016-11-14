#pragma once
#include "MeteoraDefs.h"

namespace Meteora
{
	class MathUtils
	{
	public:
		template<typename T>
		static T mod(T x, T y)
		{
			static_assert(!std::numeric_limits<T>::is_exact, "Mod: floating-point type expected");

			if (0. == y)
				return x;

			double m = x - y * floor(x / y);

			// handle boundary cases resulted from floating-point cut off:
			if (y > 0)
			{
				if (m >= y)
					return 0;

				if (m < 0)
				{
					if (y + m == y)
						return 0;
					else
						return y + m;
				}
			}
			else
			{
				if (m <= y)
					return 0;

				if (m > 0)
				{
					if (y + m == y)
						return 0;
					else
						return y + m;
				}
			}

			return m;
		}

		static double wrapPosNegPI(double fAng)
		{
			return mod<double>(fAng + M_PI, M_TWOPI) - M_PI;
		}

		// wrap [rad] angle to [0..TWO_PI)
		static double wrapTwoPI(double fAng)
		{
			return mod<double>(fAng, M_TWOPI);
		}
	};
}