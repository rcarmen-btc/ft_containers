#include "stack.hpp"
#include <deque>
#include <vector>

int main() {

	ft::stack<int> a;
	ft::stack<int, std::deque<int> > b;

	std::cout << "stack on vector: " << std::endl;
	std::cout << "	is empty:	" << a.empty() << std::endl;
	std::cout << "	size:		" << a.size() << std::endl;

	std::cout << "stack on deque: " << std::endl;
	std::cout << "	is empty:	"<< b.empty() << std::endl;
	std::cout << "	size:		" << b.size() << std::endl;
}