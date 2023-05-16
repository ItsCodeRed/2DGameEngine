#pragma once

#include "Vector2.h"
#include "Component.h"
#include "Node.h"

struct Collision
{
	Vec2 normal;
};

class Collider : public Component
{
public:
	virtual Vec2 NearestPoint(const Collider* other) const { return Vec2(0, 0); };
	virtual bool IsColliding(const Collider* other) const { return false; };
	virtual Collision ResolveCollision(Collider* other) { return Collision(); };
	virtual Collision IsOutside() const { return Collision(); };
};
