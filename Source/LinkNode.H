#ifndef U_LinkNode_H
#define U_LinkNode_H

#include "Definitions.H"

namespace U {

template<class Value_T, class Node_T>
class Link;

template<class Value_T, class Node_T>
class LinkNode {
public:
	LinkNode() = delete;
	
	virtual
	~LinkNode() = 0;
	
public:
	virtual inline constexpr
	Link<Value_T, Node_T> *link()
	noexcept = 0;

	virtual inline constexpr
	Value_T *value()
	noexcept = 0;
	
	virtual inline constexpr
	const Node_T *above()
	noexcept = 0;

public:
	virtual
	Void insertAbove(Value_T value) = 0;

	virtual
	Void insertAbove(Node_T *node) = 0;
};

}

#endif // U_LinkNode_H
