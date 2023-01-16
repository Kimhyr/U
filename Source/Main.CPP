#include "Doubly.H"
#include "Link.H"

using namespace U;

Int main() {
	Link<Int, Doubly<Int>> link;
	link.put(new Doubly<Int>(&link, 0));
	link.put(new Doubly<Int>(&link, 1));
	link.put(new Doubly<Int>(&link, 2));
	return 0;
}
