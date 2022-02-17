#include <iostream>

template<class T> inline
	T sum_all( T *first, T *last ) {
		T sum;
		for (sum = 0; first <= last; ++first)
			sum += *first;
		return sum;	
	}

int main() {

	int a[] = {1, 2, 3, 4};
	// int c = sum_all(a, &a[3]);
	hi
	// std::cout << c << std::endl;
}