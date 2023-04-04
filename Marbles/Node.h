#pragma once
#include <vector>

class Node
{
	std::vector<Node*> nodes;

public:
	Node* parent;

	virtual void Update(float dt) { }
	void Refresh(const float dt);

	void AddNode(Node*&& node)
	{
		node->parent = this;
		nodes.push_back(node);
	}
};

