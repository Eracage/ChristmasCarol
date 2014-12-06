#include <Util.hpp>


pmath::Vec2 Beziel(pmath::Vec2 p0, pmath::Vec2 p1, pmath::Vec2 p2, float t)
{
	return p0 * pow(1-t,2) + p1 * 2 * (1-t) * t + p2 * pow(t,2);
}

