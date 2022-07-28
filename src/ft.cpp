#include "utility.hpp"
#include "vector.hpp"
#include "xutility.hpp"
#include <vector>
#include <utility>
#include <iostream>
#include <assert.h>
#include <typeinfo>  


// class My_it: public ft::iterator<ft::forward_iterator_tag, char, long> {
	
// };


typedef std::iterator_traits<int *> traits;

typedef ft::pair<int, char> ft_pair_ic;
typedef std::pair<int, char> std_pair_ic;


int main() {

	std::cout << (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag)) << std::endl;

	// =======================================================================
	// PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR PAIR 
	// ------------------------------------------------------------------------

	ft_pair_ic p0;
	ft_pair_ic p1 = p0, p2(3, 'a'); 

	assert (p1.first == 0);
	assert (p1.second == 0);
	assert (p2.first == 3);
	assert (p2.second == 'a');
	assert (p2 == ft::make_pair((ft_pair_ic::first_type)3, (ft_pair_ic::second_type)'a'));
	assert (p2 < ft::make_pair((ft_pair_ic::first_type)4, (ft_pair_ic::second_type)'a'));
	assert (p2 < ft::make_pair((ft_pair_ic::first_type)4, (ft_pair_ic::second_type)'b'));
	assert (p2 < ft::make_pair((ft_pair_ic::first_type)3, (ft_pair_ic::second_type)'b'));
	assert (p1 != p2);
	assert (p2 > p1);
	assert (p2 <= p2);
	assert (p2 >= p2);

	std::cout << "\033[0;32m[SUCCESS] stack testing <utility>\033[m" << std::endl;

	// ------------------------------------------------------------------------
	// END_PAIR END_PAIR END_PAIR END_PAIR END_PAIR END_PAIR END_PAIR END_PAIR  
	// ========================================================================
	
	ft::vector<int> a;

	// =======================================================================
	// STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK STACK
	// ------------------------------------------------------------------------



	// ------------------------------------------------------------------------
	// END_STACK END_STACK END_STACK END_STACK END_STACK END_STACK END_STACK 
	// ========================================================================

}
