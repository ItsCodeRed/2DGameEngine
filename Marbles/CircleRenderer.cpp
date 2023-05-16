#include "CircleRenderer.h"
#include "WindowManager.h"

void CircleRenderer::Update(const float dt)
{
	SetColor(color);
	DrawCircle(entity->transform->position, radius);
}