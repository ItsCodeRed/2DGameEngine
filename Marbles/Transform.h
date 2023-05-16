#pragma once

#include "Node.h"
#include "Vector2.h"

class Transform : public Node
{
public:
	Vec2 position;
	float angle = 0;
};

