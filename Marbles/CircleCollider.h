#pragma once

#include "Vector2.h"
#include "Collider.h"

class CircleCollider : public Collider
{
public:
	virtual Vec2 NearestPoint(const Collider* other) const override;
	virtual bool IsColliding(const Collider* other) const override;
	virtual Collision ResolveCollision(Collider* other) override;
	virtual Collision IsOutside() const override;

	float radius = 0;
};

