#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iosfwd>
#include <vector>
#include <iostream>

namespace ft {
    
    template <class T, class C = std::vector<T> >
        class stack {
    public:
        typedef C container_type;
        typedef typename C::value_type value_type;
        typedef typename C::size_type size_type;

        // stack();
        stack(const container_type& ctnr = container_type());

        bool empty() const;
        size_type size() const;

    protected:
        C ctnr;
        };
    
}; /* namespace ft */

#endif /* _STACK_HPP_ */
