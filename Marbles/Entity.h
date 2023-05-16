#pragma once

#include "Node.h"
#include "Transform.h"

class Entity : public Node
{
public:
	Transform* transform;

	Entity()
	{
		transform = new Transform();
	}

	~Entity()
	{
		delete transform;
	}
};

