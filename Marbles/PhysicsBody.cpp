#include "PhysicsBody.h"
#include "CircleNode.h"
#include <memory>

void PhysicsBody::Update(const float dt)
{
    if (CircleNode* c = dynamic_cast<CircleNode*>(parent))
    {
        c->center += velocity * dt;
    }

    velocity -= Vec2(0, 500) * dt;
}