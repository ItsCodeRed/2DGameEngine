#include "Physics.h"

void Physics::Update(float dt)
{
	int size = bodies.size() - 1;

	for (size_t i = 0; i < bodies.size() - 1; i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			if (!bodies[i]->OverlapsBody(bodies[j])) continue;

			bodies[i]->HandleCollision(bodies[j]);
		}
	}

	//for (size_t i = 0; i < bodies.size() - 1; i++)
	//{
	//	for (size_t j = i + 1; j < bodies.size(); j++)
	//	{
	//		if (!bodies[i]->OverlapsBody(bodies[j])) continue;

	//		bodies[i]->HandleCollision(bodies[j], dt);
	//	}
	//}
}
