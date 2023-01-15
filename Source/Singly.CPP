#include "Singly.H"

namespace  U {

template<class Value_T>
Singly<Value_T>::Singly(Link<Value_T, Singly<Value_T>> *link, Value_T value)
	: link_(link), value_(value), above_(nil) {
	++link->size_;
}

template<class Value_T>
Singly<Value_T>::Singly(Link<Value_T, Singly<Value_T>> *link, Value_T value,
		        Singly<Value_T> *above)
	: link_(link), value_(value), above_(above) {
	++link->size_;
}

template<class Value_T>
Singly<Value_T>::~Singly() {
	Singly<Value_T> **node;
	for (node = &this->link_->root_; *node != this; node = &(*node)->above_);
	*node = this->above_;
	this->value_.~Value_T();
	--this->link_->size_;
}

}
