#ifndef U_Singly_H
#define U_Singly_H

#include "LinkNode.H"

namespace U {

template<class Value_T>
class Singly: LinkNode<Value_T, Singly<Value_T>> {
public:
	Singly(Link<Value_T, Singly<Value_T>> *link, Value_T value);
	Singly(Link<Value_T, Singly<Value_T>> *link, Value_T value, Singly<Value_T> *above);

	~Singly()
	override;

public:
	inline constexpr
	Link<Value_T, Singly<Value_T>> *link()
	noexcept override { return this->link_; }

 	inline constexpr
	Value_T *value()
	noexcept override { return &this->value_; }
	
	inline constexpr
	Singly<Value_T> *above()
	noexcept override { return this->above_; }

public:
	Void insertAbove(Value_T value)
	override;

	Void insertAbove(Singly<Value_T> *node)
	override;
 
private:
	Link<Value_T, Singly<Value_T>> *link_;
	Value_T value_;
	Singly<Value_T> *above_;
};

}

#endif // U_Singly_H
