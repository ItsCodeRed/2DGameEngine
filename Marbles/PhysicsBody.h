#pragma once
#include "Node.h"
#include "Vector2.h"

class PhysicsBody : public Node
{
public:
	Vec2 velocity;

	virtual void Update(const float dt) override;
};

