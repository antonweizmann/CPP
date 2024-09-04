

#include "Base.hpp"

int main(void) {
	Base *base_array[10];
	for (int i = 0; i < 4; i++) {
		base_array[i] = generate();
		std::cout << "Pointer " << i << " of array is: ";
		identify(base_array[i]);
		std::cout << "Reference " << i << " of array is: ";
		identify(*base_array[i]);
		std::cout << std::endl;
		delete base_array[i];
	}
}
