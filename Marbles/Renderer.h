#pragma once

#include "Color.h"
#include "Vector2.h"
#include "Component.h"

class Renderer : public Component
{
public:
	void SetColor(Color color);
	void DrawCircle(Vec2 center, float radius);
};

