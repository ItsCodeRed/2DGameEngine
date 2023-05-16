#include "Node.h"

void Node::Initialize()
{
	Start();
	hasStarted = true;

	for (Node* node : nodes)
	{
		node->Initialize();
	}
}

void Node::Refresh(const float dt)
{
	if (!hasStarted)
	{
		Start();
	}

	Update(dt); // update every frame

	for (Node* node : nodes)
	{
		node->Refresh(dt); // updates child nodes every frame
	}
}