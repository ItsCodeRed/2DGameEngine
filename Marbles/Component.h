#pragma once

#include "Entity.h"

class Component : public Node
{
public:
	Entity* entity = nullptr;

	virtual void Start() override;
};

