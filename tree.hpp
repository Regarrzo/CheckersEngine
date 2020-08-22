#pragma once

#include <vector>

namespace tree
{
	template <typename T>
	class Node
	{
	public:
		Node(T content) : content(content), parent(nullptr), children() {}
		Node(T content, std::vector<Node> children) : content(content), parent(nullptr), children(children) {}

		void addChild(Node child)
		{
			child.parent = this;
			children.push_back(child);
		}

		T content;
		Node *parent;
		std::vector<Node> children;
	};
} // namespace tree