#include "Vector2.h"

std::ostream& operator << (std::ostream& outs, const Vec2& v)
{
	return outs << "(" << v.x << "," << v.y << ")";
}

Vec2 operator*(const Vec2& v, const float n)
{
	return Vec2(v.x * n, v.y * n);
}

Vec2 operator/(const Vec2& v, const float n)
{
	return Vec2(v.x / n, v.y / n);
}

Vec2 operator*(const float n, const Vec2& v)
{
	return Vec2(v.x * n, v.y * n);
}

Vec2 operator/(const float n, const Vec2& v)
{
	return Vec2(v.x / n, v.y / n);
}