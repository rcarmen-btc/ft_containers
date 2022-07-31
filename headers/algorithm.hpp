// algoritm template file
#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_
#include <iosfwd>
#include "utility.hpp"

namespace ft {
    template<class InIt1, class InIt2>
        bool lexicographical_complare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2) {
            for (; first1 != last1 && first2 != last2; ++first1, ++last2) {
                if (*first1 < *first2)
                    return (true);
                else if (*first2 < *first1)
                    return (false);
                return (first1 == last1 && first2 != last2);
            }
        }

    template<class InIt1, class InIt2, class Pred>
        bool lexicographical_complare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2, Pred pr) {
            for (; first1 != last1 && first2 != last2; ++first1, ++last2) {
                if (pr(*first1, *first2))
                    return (true);
                else if (pr(*first2, *first1))
                    return (false);
                return (first1 == last1 && first2 != last2);
            }
        }

    template<class InIt1, class InIt2>
        pair<InIt1, InIt2> mismatch(InIt1 first, InIt2 last, InIt2 x) {
            for (; first != last && *first == *x; ++first, ++x)
                ;
            return (pair<InIt1, InIt2>(first, last));
        }

    template<class InIt1, class InIt2, class Pr>
        pair<InIt1, InIt2> mismatch(InIt1 first, InIt2 last, InIt2 x, Pr pr) {
            for (; first != last && pr(*first, *last); ++first, ++x)
                ;
            return (pair<InIt1, InIt2>(first, last));
        }

    template<class InIt1, class InIt2>
        bool equal(InIt1 first, InIt1 last, InIt2 x) {
            return (mismatch(first, last, x).first == last);
        }

    template<class InIt1, class InIt2, class Pred>
        bool equal(InIt1 first, InIt1 last, InIt2 x, Pred pr) {
            return (mismatch(first, last, x, pr).first == last);
        }

    template<class BidIt1, class BidIt2>
        BidIt2 copy_backward(BidIt1 first, BidIt1 last, BidIt2 x) {
            while (first != last) {
                *--x = *--last;
            }
            return (x);
        }

    template<class FwdIt, class T>
        void fill(FwdIt first, FwdIt last, const T &x);

    template<class T> inline
        void swap(T &X, T &Y) {
            T tmp = X;
            X = Y;
            Y = tmp;
        }
    
    template<typename> struct is_integral_base: std::false_type {};

    template<> struct is_integral_base<bool>: std::true_type {};
    template<> struct is_integral_base<int>: std::true_type {};
    template<> struct is_integral_base<short>: std::true_type {};

    template<typename T> struct is_integral: is_integral_base<std::remove_cv_t<T>> {};

}; /* namespace ft */

#endif /* _ALGORITHM_HPP_ */