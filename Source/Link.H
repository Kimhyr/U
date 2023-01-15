#ifndef U_Link_H
#define U_Link_H

#include "LinkNode.H"

namespace U {

template<class Value_T, class Node_T = LinkNode<Value_T, class Node_T>>
class Link {
public:
	friend class LinkNode<Value_T, Node_T>;

public:
	Link();

	~Link();

public:
	inline constexpr
	Node_T *root()
	noexcept { return this->root_; }

	inline constexpr
	Node_T *head()
	noexcept { return this->head_; }

	inline constexpr
	Nat64 size()
	const noexcept { return this->size_; }

	Node_T *get(Nat64 index);
	Node_T *get(Value_T value)
	noexcept;

public:
	Void put(Node_T *node);

private:
	Node_T *root_;
	Node_T *head_;
	Nat64 size_;
};

}

#endif // U_Link_H
