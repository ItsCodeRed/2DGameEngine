#pragma once
#include "Color.h"
#include "Vector2.h"

class Renderer
{
public:
	void SetColor(Color color);
	void DrawCircle(Vec2 center, float radius);
};

