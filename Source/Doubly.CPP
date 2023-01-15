#include "Doubly.H"

namespace U {

template<typename Value_T>
Doubly<Value_T>::Doubly(Link<Value_T, Doubly> *link, Value_T value)
	: link_(link), value_(value), under_(nil), above_(nil) {
	++link->size_;
}

template<typename Value_T>
Doubly<Value_T>::Doubly(Link<Value_T, Doubly> *link, Value_T value, Doubly *under)
	: link_(link), value_(value), under_(under), above_(nil) {
	++link->size_;
}

template<typename Value_T>
Doubly<Value_T>::Doubly(Link<Value_T, Doubly> *link, Value_T value, Doubly *under,
			Doubly *above)
	: link_(link), value_(value), under_(under), above_(above) {
	++link->size_;
}

template<typename Value_T>
Doubly<Value_T>::~Doubly() {
	if (this->under_)
		this->under_->above_ = this->above_;
	if (this->above_)
		this->above_->under_ = this->under_;
	this->value.~Value_T();
	--this->link_->size_;
}

template<typename Value_T>
Void Doubly<Value_T>::insertAbove(Value_T value) {
	auto node = new Doubly<Value_T>(this->link_, value, this, this->above_);
	if (this->above_)
		this->above_->under_ = node;
	this->above_ = node;
}

template<class Value_T>
Void Doubly<Value_T>::insertAbove(Doubly<Value_T> *node) {
	if (this->above_)
		this->above_->under = node;
	this->above_ = node;
}

template<typename Value_T>
Void Doubly<Value_T>::insertUnder(Value_T value) {
	auto node = new Doubly<Value_T>(this->link_, value, this->under_, this);
	if (this->under_)
		this->under_->above_ = node;
	this->under_ = node;
}

template<class Value_T>
Void Doubly<Value_T>::insertUnder(Doubly<Value_T> *node) {
	if (this->under_)
		this->under_->above_ = node;
	this->under_ = node;
}

}
