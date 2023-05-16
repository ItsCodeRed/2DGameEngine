#pragma once

#include <vector>

class Node
{
	std::vector<Node*> nodes;
	bool hasStarted = false;

public:
	Node* parent = nullptr;

	virtual void Start() { }
	virtual void Update(float dt) { }
	void Initialize();
	void Refresh(const float dt);

	void AddNode(Node& node)
	{
		node.parent = this;
		nodes.push_back(&node);
	}

	template <class T>
	T* AddNode()
	{
		T* newType = new T();
		Node* newNode = newType;

		newNode->parent = this;
		nodes.push_back(newNode);

		return newType;
	}

	template <class T>
	T* GetChildNode()
	{
		for (Node* node : nodes)
		{
			if (T* typedNode = dynamic_cast<T*>(node))
			{
				return typedNode;
			}
		}

		return nullptr;
	}

	template <class T>
	std::vector<T*> GetChildNodes()
	{
		std::vector<T*> childNodes;
		for (Node* node : nodes)
		{
			if (T* typedNode = dynamic_cast<T*>(node))
			{
				childNodes.push_back(typedNode);
			}
		}

		return childNodes;
	}

	~Node()
	{
		for (Node* node : nodes)
		{
			delete node;
		}
	}
};

