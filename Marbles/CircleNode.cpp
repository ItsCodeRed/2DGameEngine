#include "CircleNode.h"

void CircleNode::Update(const float dt)
{
	renderer.SetColor(color);
	renderer.DrawCircle(center, radius);
}