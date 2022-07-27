// utility template header
#ifndef _UTILITY_HPP_
#define _UTILITY_HPP_
#include <iosfwd>


namespace ft {
    // template struct PAIR
    template<class T1, class T2>
        struct pair {
            typedef T1 first_type;
            typedef T2 second_type;
            
            T1 first;
            T2 second;

            pair():
                first(T1()), second(T2()) {}
            pair(const T1 &x, const T2 &y): 
                first(x), second(y) {}
            template <class V1, class V2>
                pair(const pair<V1, V2> &pr): 
                    first(pr.first), second(pr.second) {}
        };

    
    // PAIR template operators
    template <class T1, class T2>
        pair<T1, T2> make_pair(const T1 &x, const T2 &y)
            { return (pair<T1, T2>(x, y)); }        

    template <class T1, class T2>
        bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (!(x == y)); }

    template <class T1, class T2>
        bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (x.first == y.first && x.second == y.second); }

    template <class T1, class T2>
        bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (x.first < y.first || !(y.first < x.first) && x.second < y.second); }
            
    template <class T1, class T2>
        bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (!(y < x)); }

    template <class T1, class T2>
        bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (y < x); }
    
    template <class T1, class T2>
        bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
            { return (!(x < y)); }

    // template operators
    template <class T1>
        bool operator!=(const T1 &x, const T1 &y)
            { return (!(x == y)); }

    template <class T1>
        bool operator<=(const T1 &x, const T1 &y)
            { return (!(y < x)); }

    template <class T1>
        bool operator>(const T1 &x, const T1 &y)
            { return (y < x); }

    template <class T1>
        bool operator>=(const T1 &x, const T1 &y)
            { return (!(x < y)); }

}; /* namespace ft */

#endif /* _UTILITY_HPP_ */