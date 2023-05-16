#pragma once

#include <vector>
#include "PhysicsBody.h"

class Physics : public Node
{
	std::vector<PhysicsBody*> bodies;

public:
	void AddBody(PhysicsBody* body)
	{
		bodies.push_back(body);
	}

	static constexpr float gravity = 10;

	virtual void Update(float dt) override;
};

