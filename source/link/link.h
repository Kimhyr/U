#ifndef u_link_link_h$
#define u_link_link_h$

#include "../definitions.h"

namespace U {

template<class Value_T, class Node_T>
class Link;

template<class Value_T, class Node_T>
class LinkNode {
public:
	using This = Node_T;

public:
	LinkNode() = delete;
	
	virtual
	~LinkNode() = 0;
	
public:
	virtual inline constexpr
	Link<Value_T, Node_T> *link()
	const noexcept = 0;

	virtual inline constexpr
	Value_T *value()
	noexcept = 0;
	
	virtual inline constexpr
	Node_T *above()
	const noexcept = 0;

public:
	virtual
	Void insertAbove(Value_T value) = 0;

	virtual
	Void insertAbove(Node_T *node) = 0;
};

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
	const noexcept { return this->root_; }

	inline constexpr
	Node_T *head()
	const noexcept { return this->head_; }

	inline constexpr
	Nat64 size()
	const noexcept { return this->size_; }

	Node_T *get(Nat64 index)
	const noexcept;
	Node_T *get(Value_T value)
	const noexcept;

public:
	Void put(Node_T *node);

private:
	Node_T *root_;
	Node_T *head_;
	Nat64 size_;
};

}

#endif // u_link_link_h$
