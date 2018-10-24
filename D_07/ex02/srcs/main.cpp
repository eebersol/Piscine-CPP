#include "Array.tpp"
#include <stdexcept>
#include <iostream>

// template <class T>
// class Array;

int main() {
	unsigned int i = 10;

    Array<int> a = Array<int>(i);
    
    for (unsigned int j =0; j < i; j++) {
        a[j] = 42;
    }

    Array<int> b(a);

    b[5] = 0;

    Array<int> c = b;

    c[1] = 9;

    for (unsigned int j =0; j < i; j++) {
        std::cout << std::to_string(a[j]) << " ";
    }

    std::cout << std::endl;

    for (unsigned int k =0; k < i; k++) {
        std::cout << std::to_string(b[k]) << " ";
    }

    std::cout << std::endl;

    for (unsigned int k =0; k < i; k++) {
        std::cout << std::to_string(c[k]) << " ";
    }

    std::cout << std::endl;

	return 0;
}