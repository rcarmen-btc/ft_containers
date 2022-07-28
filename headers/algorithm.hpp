// algoritm template file
#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_
#include <iosfwd>

namespace ft {
    template<class InIt1, class InIt2>
        bool lexicographical_complare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2);

    template<class InIt1, class InIt2, class Pred>
        bool lexicographical_complare(InIt1 first1, InIt1 last1, InIt2 first2, InIt2 last2, Pred pr);

    template<class InIt1, class InIt2>
        bool equal(InIt1 first, InIt1 last, InIt2 x);

    template<class InIt1, class InIt2, class Pred>
        bool equal(InIt1 first, InIt1 last, InIt2 x, Pred pr);

    template<class BidIt1, class BidIt2>
        BidIt2 copy_backward(BidIt1 first, BidIt1 last, BidIt2 x);

    template<class FwdIt, class T>
        void fill(FwdIt first, FwdIt last, const T &x);

    template<class T> inline
        void swap(T &X, T &Y) {
            T tmp = X;
            X = Y;
            Y = tmp;
        }

}; /* namespace ft */

#endif /* _ALGORITHM_HPP_ */