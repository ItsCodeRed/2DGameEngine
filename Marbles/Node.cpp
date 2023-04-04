#include "Node.h"

void Node::Refresh(const float dt)
{
	Update(dt);

	for (Node* node : nodes)
	{
		node->Refresh(dt);
	}
}