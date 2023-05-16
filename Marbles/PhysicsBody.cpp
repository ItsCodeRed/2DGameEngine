#include "PhysicsBody.h"
#include "Physics.h"
#include "CircleRenderer.h"
#include "WindowManager.h"
#include <memory>

void PhysicsBody::Start()
{
    Component::Start();
    colliders = parent->GetChildNodes<Collider>();
    oldPos = entity->transform->position;
}

bool PhysicsBody::OverlapsBody(const PhysicsBody* body)
{
    for (Collider* col1 : colliders)
    {
        for (Collider* col2 : body->colliders)
        {
            if (col1->IsColliding(col2))
            {
                return true;
            }
        }
    }

    return false;
}

void PhysicsBody::HandleCollision(PhysicsBody* body)
{
    for (Collider* col1 : colliders)
    {
        for (Collider* col2 : body->colliders)
        {
            Collision collision = col1->ResolveCollision(col2);

            Vec2 velDiff = body->velocity - velocity;

            velocity += collision.normal * (velDiff.dot(collision.normal) * bounciness);
            body->velocity += collision.normal * (-velDiff.dot(collision.normal) * body->bounciness);
        }
    }
}

void PhysicsBody::Update(float dt)
{
    velocity -= Vec2(0, Physics::gravity) * dt;
    for (Collider* col : colliders)
    {
        Collision collision = col->IsOutside();
        if (collision.normal.magnitude() > 0.9f)
        {
            velocity += collision.normal * (-velocity.dot(collision.normal) * (1 + bounciness));
        }
    }

    entity->transform->position += velocity * dt;
    oldPos = entity->transform->position;
}