#include "CircleCollider.h"
#include "WindowManager.h"
#include <math.h>

Vec2 CircleCollider::NearestPoint(const Collider* other) const
{
	Vec2 otherPos = other->entity->transform->position;
	Vec2 myPos = entity->transform->position;
	return myPos + (otherPos - myPos).normalize() * std::fminf(radius, (otherPos - myPos).magnitude());
}

bool CircleCollider::IsColliding(const Collider* other) const
{
	Vec2 myPos = entity->transform->position;
	return (myPos - other->NearestPoint(this)).magnitude() < radius;
}

Collision CircleCollider::IsOutside() const
{
	Vec2 myPos = entity->transform->position;
	Collision colInfo = Collision();

	if (myPos.x + radius > WindowManager::currentWindow->windowSize.x / 2)
	{
		colInfo.normal = Vec2(-1, 0);
		entity->transform->position.x = WindowManager::currentWindow->windowSize.x / 2 - radius;
	}
	else if (myPos.x - radius < -WindowManager::currentWindow->windowSize.x / 2)
	{
		colInfo.normal = Vec2(1, 0);
		entity->transform->position.x = -WindowManager::currentWindow->windowSize.x / 2 + radius;
	}
	else if (myPos.y + radius > WindowManager::currentWindow->windowSize.y / 2)
	{
		colInfo.normal = Vec2(0, -1);
		entity->transform->position.y = WindowManager::currentWindow->windowSize.y / 2 - radius;
	}
	else if (myPos.y - radius < -WindowManager::currentWindow->windowSize.y / 2)
	{
		colInfo.normal = Vec2(0, 1);
		entity->transform->position.y = -WindowManager::currentWindow->windowSize.y / 2 + radius;
	}

	return colInfo;
}

Collision CircleCollider::ResolveCollision(Collider* other)
{
	Vec2 otherPos = other->entity->transform->position;
	Vec2 myPos = entity->transform->position;
	Vec2 normal = (myPos - otherPos).normalize();
	float overlappingAmount = (myPos - other->NearestPoint(this)).magnitude();

	entity->transform->position += normal * (radius - overlappingAmount) / 2;
	other->entity->transform->position -= normal * (radius - overlappingAmount) / 2;
	
	Collision colInfo = Collision();
	colInfo.normal = normal;

	return colInfo;
}
