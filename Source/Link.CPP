#include "Link.H"

#include "Error.H"

namespace U {

template<class Value_T, class Node_T>
Link<Value_T, Node_T>::Link()
	: root_(nil), head_(nil), size_(0) {}

template<class Value_T, class Node_T>
Link<Value_T, Node_T>::~Link() {
	for (Node_T *node; this->root_; this->root_ = node) {
		node = this->root_;
		delete this->root_;
	}
}

template<class Value_T, class Node_T>
Node_T *Link<Value_T, Node_T>::get(Nat64 index) {
	if (index + 1 >= this->size_)
		throw Error::OUT_OF_RANGE;
	Node_T *node;
	for (node = this->root_; node; node = node->above())
		if (--index == 0)
			break;
	return node;
}

template<class Value_T, class Node_T>
Node_T *Link<Value_T, Node_T>::get(Value_T value)
noexcept {
	Node_T *node;
	for (node = this->root_; node; node = node->above())
		if (node->value() == value)
			break;
	return node;
}

template<class Value_T, class Node_T>
Void Link<Value_T, Node_T>::put(Node_T *node) {
	if (this->head_) {
		this->head_->insertAbove(node);
		return;
	}
	this->head_ = node;
	this->root_ = this->head_;
}

}
