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
        stack(const container_type& ctnr = container_type()): c(ctnr) {}
        bool empty() const 
            { return (c.empty()); }
        size_type size() const 
            { return (c.size()); }
        value_type& top()
            { return (c.back()); }
        const value_type& top() const 
            { return (c.back()); };
        void push(const value_type& x) 
            { c.push_back(x); }
        void pop()
            { c.pop_back(); }
        bool Eq(const stack<T, C>& X) const 
            { return (c == X.c); };
        bool Lt(const stack<T, C>& X) const
            { return (c < X.c); }
    protected:
        C c;
        };
    
    template<class T, class C>
        bool operator==(const stack<T, C>& X, const stack<T, C>& Y)
            { return (X.Eq(Y)); }
    template<class T, class C>
        bool operator!=(const stack<T, C>& X, const stack<T, C>& Y)
            { return !(X.Eq(Y)); }
    template<class T, class C>
        bool operator<(const stack<T, C>& X, const stack<T, C>& Y)
            { return (X.Lt(Y)); }
    template<class T, class C>
        bool operator>(const stack<T, C>& X, const stack<T, C>& Y)
            { return (Y < X); }
    template<class T, class C>
        bool operator>=(const stack<T, C>& X, const stack<T, C>& Y)
            { return !(X < Y); }
    template<class T, class C>
        bool operator<=(const stack<T, C>& X, const stack<T, C>& Y)
            { return !(X > Y); }
}; /* namespace ft */
#endif /* _STACK_HPP_ */
