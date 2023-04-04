#pragma once
#include "Node.h";
#include "Renderer.h";

class CircleNode : public Node
{
	Renderer renderer;
public:
	CircleNode(Vec2 center, float radius, Color color)
	{
		this->center = center;
		this->radius = radius;
		this->color = color;
	}

	virtual void Update(float dt) override;

	float radius = 0;
	Vec2 center;
	Color color;
};

