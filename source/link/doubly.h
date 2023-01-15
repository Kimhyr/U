#ifndef u_link_doubly_h$
#define u_link_doubly_h$

#include "link.h"

namespace U {

template<class Value_T>
class Doubly: LinkNode<Value_T, Doubly<Value_T>> {
public:
	Doubly(Link<Value_T, Doubly<Value_T>> *link, Value_T value);
	Doubly(Link<Value_T, Doubly<Value_T>> *link, Value_T value,
	       Doubly<Value_T> *under);
	Doubly(Link<Value_T, Doubly<Value_T>> *link, Value_T value,
	       Doubly<Value_T> *under, Doubly<Value_T> *above);

	~Doubly()
	override;

public:
	inline constexpr
	Link<Value_T, Doubly<Value_T>> *link()
	const noexcept override { return this->link_; }

	inline constexpr
	Value_T *value()
	noexcept override { return &this->value_; }

	inline constexpr
	Doubly<Value_T> *above()
	const noexcept override { return this->above_; }
	
	inline constexpr
	Doubly<Value_T> *under()
	const noexcept { return this->under_; }

public:
	Void insertAbove(Value_T value)
	override;
	Void insertAbove(Doubly<Value_T> *node)
	override;

	Void insertUnder(Value_T value);
	Void insertUnder(Doubly<Value_T> *node);

private:
	Link<Value_T, Doubly> *link_;
	Value_T value_;
	Doubly<Value_T> *above_;
	Doubly<Value_T> *under_;
};

}

#endif // u_link_doubly_h$
