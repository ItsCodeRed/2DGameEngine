#pragma once

#include "Node.h"
#include "Transform.h"
#include "Entity.h"
#include "Vector2.h"
#include "Collider.h"
#include "Component.h"
#include <vector>
#include <iostream>

class PhysicsBody : public Component
{
	Vec2 oldPos;

public:
	std::vector<Collider*> colliders;

	Vec2 velocity;
	float bounciness = 1.0f;

	virtual void Start() override;
	virtual void Update(float dt) override;

	bool OverlapsBody(const PhysicsBody* body);

	void HandleCollision(PhysicsBody* body);
};

