#ifndef _TEMPLATES_HPP_
#define _TEMPLATES_HPP_

//=========INCLUSIONS===========//
#include <iosfwd>
#include <assert.h>
#include <deque>
#include <list>
#include <vector>
#include <stack>
#include <chrono>
#include "stack.hpp"
#include <ctime>

//===========COLORS=============//
#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define BLUE "\e[94m"
#define MAGENTA "\e[95m"
#define CYAN "\e[96m"
#define BOLD "\e[1m"
#define BG_RED "\e[101m"
#define BG_GREEN "\e[102m"
#define BG_YELLOW "\e[103m"
#define BG_BLUE "\e[104m"
#define BG_MAGENTA "\e[105m"
#define BG_CYAN "\e[106m"
#define CEND "\e[0m"

//===============TEMPLATES===============//
template <class T>
	void print_all_el_of_cont(T& c) {
		std::cout << YELLOW << "║	size: " << c.size() << "			       ╚╝" << std::endl;
		typename T::iterator it = c.begin();
		std::cout <<  "║	[";
		while (it != c.end()) {
			std::cout << *it;
			std::cout << ", ";
			it++;
		}
		std::cout << "]				" << std::endl;
		std::cout << "╚════════════════════════════════════════╗" << std::endl << std::endl;
	}


template <class T>
	void print_stack(T s, int color = 0) {
		std::cout << RED;
		if (color == 0)
			std::cout << GREEN;
		std::cout << "		Stack elements:" << std::endl;
        while (!s.empty()) {
            std::cout << "		║	" << s.top() << "	║" << std::endl;
            s.pop();
        }
        std::cout << "		╚═══════════════╝" << std::endl;
    }

template <class T>
	void print_stack_status(const T& s, int color = 0) {
		std::cout << MAGENTA;
		if (color == 0)
			std::cout << CYAN;
		std::cout << std::endl << "		is empty:	"  << s.empty() << std::endl << "		size:		" << s.size() << std::endl;
		if (!s.empty()) {
			std::cout << "		top:		" << s.top() << std::endl;
            print_stack(s, color);
        }
	}

template <class T, class Z>
	void push_stack_and_print(T& st, Z val, std::string type, int color = 0) {
		std::cout << RED;
		if (color == 0)
			std::cout << GREEN;
		std::cout << std::endl << "	push(" << val << ") =>" << std::endl;
		unsigned int start_time =  clock(); 
		st.push(val);
		double search_time_d = static_cast<double>(clock() - start_time) / 1000;
		std::cout << BLUE;
		if (!type.find("std"))
			std::cout << GREEN;
		print_stack_status(st, color);
		std::cout << "		" << type << " stack push: " << search_time_d << std::endl;

	}

template <class T>
	void pop_stack_and_print(T& st, std::string type, int color = 0) {
		std::cout << GREEN << "	pop() <= " << std::endl;
		unsigned int start_time =  clock(); 
		st.pop();
		double search_time_d = static_cast<double>(clock() - start_time) / 1000;
		std::cout << BLUE;
		if (!type.find("std"))
			std::cout << GREEN;
		print_stack_status(st, color);
		std::cout << "		" << type << " stack pop: " << search_time_d << std::endl;
	}

template <class T, class D>
	void univ_test(T& st, D& ctnr, std::string type) {
		T tmp;
		std::cout << std::endl << YELLOW << BOLD  << "╔═══════════════════════╗" << std::endl << "║ container:		╚═══════════════╗" << CEND << std::endl;
		print_all_el_of_cont(ctnr);
		print_stack_status(st);

  	    push_stack_and_print(st, 3, type);
  	    push_stack_and_print(st, 42, type);
  	    push_stack_and_print(st, 92, type);

		pop_stack_and_print(st, type);
		pop_stack_and_print(st, type);
		pop_stack_and_print(st, type);

		push_stack_and_print(tmp, 4, type, 1);
		push_stack_and_print(tmp, 4, type, 1);
		push_stack_and_print(tmp, 4, type, 1);

		std::cout << CYAN <<  "	╔═══════════════════════════════════════════════╗	" << std::endl;
		std::cout << GREEN << "		" << " stack" << CYAN << " == " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st == tmp) <<  "					" << std::endl;
		std::cout << GREEN << "		" << " stack" << CYAN << " != " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st != tmp) <<  "					" << std::endl;
		std::cout << GREEN << "		" << "  stack" << CYAN << " > " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st > tmp) <<  "					" << std::endl;
		std::cout << GREEN << "		" << "  stack" << CYAN << " < " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st < tmp) <<  "					" << std::endl;
		std::cout << GREEN << "		" << " stack" << CYAN << " >= " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st >= tmp) <<  "					" << std::endl;
		std::cout << GREEN << "		" << " stack" << CYAN << " <= " << RED  << " tmp stack	" << std::endl;
		std::cout << CYAN <<  "			" << (st <= tmp) <<  "				║	" << std::endl;
		std::cout << CYAN <<  "	╚═══════════════════════════════════════════════╝	" << std::endl;
	}

#endif /* _TEMPLATES_HPP_ */
