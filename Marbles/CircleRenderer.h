#pragma once

#include "Node.h"
#include "Renderer.h"
#include "PhysicsBody.h"
#include "Renderer.h"

class CircleRenderer : public Renderer
{
public:
	CircleRenderer()
	{
		
	}

	CircleRenderer(float radius, Color color)
	{
		this->radius = radius;
		this->color = color;
	}

	virtual void Update(float dt) override;

	float radius = 0;
	Color color;
};

