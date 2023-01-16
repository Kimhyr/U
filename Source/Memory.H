#ifndef U_Memory_H
#define U_Memory_H

#include "Definitions.H"

namespace U {

template<class Data_T>
class Memory {
public:
	static
	Data_T *reallocate(Nat64 size, Data_T **data, Nat64 space);
};

}

#endif // U_Memory_H
