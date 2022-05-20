#include "templates.hpp"

int main() {

	//=======================================================================
	//STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK
	//=================deque, list, vector with int elements=================
	std::deque<int> int_de(3, 4);
	std::list<int> int_li(3, 3);
	std::vector<int> int_ve(9, 5);
	std::vector<int> int_ve_tmp;
	//=================stack from deque, list, vector with int elements================
	std::stack<int, std::deque<int> > int_de_st(int_de);
	std::stack<int, std::list<int> > int_li_st(int_li);
	std::stack<int, std::vector<int> > int_ve_st(int_ve);
	std::stack<int, std::vector<int> > int_ve_st_tmp(int_ve_tmp);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << RED << "╔═══════════════════════════════════════════════╗" << std::endl;
	std::cout << RED << "╚═══════════════INT══STACK══TEST════════════════╗" << std::endl;
	std::cout << RED << "╚═══════════════════════════════════════════════╝" << std::endl;
	univ_test(int_de_st, int_de,"std deque");
	univ_test(int_li_st, int_li, "std list");
	univ_test(int_ve_st, int_ve, "std vector");
	univ_test(int_ve_st_tmp, int_ve_tmp, "std vector");
	std::cout << std::endl;
	std::cout << std::endl;
	//========================================================================
	//ENDSTACK ENDSTACK ENDSTACK ENDSTACK ENDSTACK ENDSTACK ENDSTACK ENDSTACK 
	//========================================================================

}
