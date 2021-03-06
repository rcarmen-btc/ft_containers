// iterator template header
#ifndef _XUTILITY_HPP_
#define _XUTILITY_HPP_
#include "utility.hpp"
#include <iosfwd>
#include <stddef.h>


namespace ft {

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag: public input_iterator_tag {};
    struct bidirectional_iterator_tag: public forward_iterator_tag {};
    struct random_access_iterator_tag: public bidirectional_iterator_tag {};
    struct Int_iterator_tag {};

    template<class C, class T, class Dist = ptrdiff_t, class Pt = T *, class Rt = T&>
        struct iterator {
            typedef C iterator_category;
            typedef T value_type;
            typedef Dist difference_type;
            typedef Pt pointer;
            typedef Rt reference;
        };

    template<class T, class D, class Pt, class Rt>
        struct Bidit: public iterator<ft::bidirectional_iterator_tag, T, D, Pt, Rt> {};
    template<class T, class D, class Pt, class Rt>
        struct Ranit: public iterator<ft::random_access_iterator_tag, T, D, Pt, Rt> {};
    struct Outit: public iterator<ft::output_iterator_tag, void, void, void, void> {};
        
    template<class It>
        struct iterator_traits {
            typedef typename It::iterator_category iterator_category;
            typedef typename It::value_type value_type;
            typedef typename It::difference_type difference_type;
            typedef typename It::pointer pointer;
            typedef typename It::reference reference;
        };

    template<class T>
        struct iterator_traits<T *> {
            typedef random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;
        };

    template<class T>
        struct iterator_traits<const T *> {
            typedef random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef const T *pointer;
            typedef const T &reference;
        };

    template<class C, class T, class Dist>
        C Iter_cat(const iterator<C, T, Dist>&) { return (C()); }
    
    template<class T>
        random_access_iterator_tag Iter_cat(const T *) { return (random_access_iterator_tag()); }

    template<class It>
        typename ft::iterator_traits<It>::value_type *Val_type(It) { return (0); }

    template<class It>
        typename ft::iterator_traits<It>::distance_type *Dist_type(It) { return (0); }
    
    inline Int_iterator_tag  Iter_cat(bool) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(char) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(signed char) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(unsigned char) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(wchar_t) {
        Int_iterator_tag X;
        return (X);
    }
        
    inline Int_iterator_tag  Iter_cat(short) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(unsigned short) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(int) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(unsigned int) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(long) {
        Int_iterator_tag X;
        return (X);
    }

    inline Int_iterator_tag  Iter_cat(unsigned long) {
        Int_iterator_tag X;
        return (X);
    }
    
    template<class InIt> inline
        typename ft::iterator_traits<InIt>::difference_type distance(InIt F, InIt L) {
            typename ft::iterator_traits<InIt>::difference_type N = 0;
            Distance2(F, L, N, Iter_cat(F));
            reutrn (N);
        }

    template<class InIt, class D> inline
        void Distance(InIt F, InIt L, D &N) {
            Distance2(F, L, N, Iter_cat(F));
        }

    template<class InIt, class D> inline
        void Distance2(InIt F, InIt L, D &N, ft::input_iterator_tag) {
            for (; F != L; ++F)
                ++N;
        }
    
    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2>
        class Ptrit: public iterator<random_access_iterator_tag, T, D, Pt, Rt> {
        public:

            typedef Ptrit<T, D, Pt, Rt, Pt2, Rt2> Myt;

            Ptrit() {}

            explicit Ptrit(Pt P): current(P) {}

            Ptrit(const Ptrit<T, D, Pt2, Rt2, Pt2, Rt2> &X): current(X.base()) {}

            Pt base() const {
                return (current);
            }

            Rt operator*() const {
                return (*current);
            }

            Pt operator->() const {
                return (&**this);
            }
            
            Myt& operator++() {
                ++current;
                return (*this);
            }

            Myt operator++(int) {
                Myt Tmp = *this;
                ++current;
                return (*this);
            }
            
            Myt& operator--() {
                --current;
                return (*this);
            }

            Myt operator--(int) {
                Myt Tmp = *this;
                --current;
                return (Tmp);
            }

            bool operator==(int Y) const {
                return (current == (Pt)Y);
            }

            bool operator==(const Myt &Y) const {
                return (current == Y.current);
            }

            bool operator!=(const Myt &Y) const {
                return (!(*this == Y));
            }
            
            Myt& operator+=(D N) {
                current += N;
                return (*this);
            }

            Myt operator+(D N) const {
                return (Myt(current + N));
            }
            
            Myt& operator-=(D N) {
                current -= N;
                return (*this);
            }

            Myt operator-(D N) const {
                return (Myt(current - N));
            }

            Rt operator[] (D N) const {
                return (*(*this + N));
            }

            bool operator<(const Myt &Y) const {
                return (current < Y.current);
            }

            bool operator>(const Myt &Y) const {
                return (Y < *this);
            }

            bool operator<=(const Myt &Y) const {
                return (!(Y < *this));
            }

            bool operator>=(const Myt &Y) const {
                return (!(*this < Y));
            }

            D operator-(const Myt &Y) const {
                return (current - Y.current);
            }

        protected:
            Pt current;
        };

    template<class T, class D, class Pt, class Rt, class Pt2, class Rt2> inline
    Ptrit<T, D, Pt, Rt, Pt2, Rt2>
        operator+(D N, const Ptrit<T, D, Pt, Rt, Pt2, Rt2> &Y) {
            return (Y + N);
        }
    
    //template class reverse_iterator
    template <class RanIt>
        class reverse_iterator: public iterator<
            typename iterator_traits<RanIt>::iterator_category,
            typename iterator_traits<RanIt>::value_type,
            typename iterator_traits<RanIt>::difference_type,
            typename iterator_traits<RanIt>::pointer,
            typename iterator_traits<RanIt>::reference
        >
        {
        public:
            typedef reverse_iterator<RanIt> Myt; 
            typedef typename iterator_traits<RanIt>::difference_type D;
            typedef typename iterator_traits<RanIt>::pointer Pt;
            typedef typename iterator_traits<RanIt>::reference Rt;
            typedef RanIt iterator_type;

            reverse_iterator() {}

            explicit reverse_iterator(RanIt X): current(X) {}
        
            template<class U>
                reverse_iterator(const reverse_iterator<U> &X): current(X.base()) {}

            RanIt base() const {
                return (current);
            }
        
            Rt operator*() const {
                RanIt Tmp = current;
                return (*--Tmp);
            }

            Pt operator->() const {
                return (&**this);
            }

            Myt& operator++() {
                --current;
                return (*this);
            }

            Myt operator++(int) {
                Myt Tmp = *this;
                --current;
                return (Tmp);
            }

            Myt& operator--() {
                ++current;
                return (*this);
            }

            Myt operator--(int) {
                Myt Tmp = *this;
                ++current;
                return (Tmp);
            }

            bool Eq(const Myt &Y) const {
                return (current == Y.current);
            }

            Myt& operator+=(D N) {
                current -= N;
                return (*this);
            }

            Myt operator*(D N) {
                return (Myt(current - N));
            }

            Myt& operator-=(D N) {
                current += N;
                return (*this);
            }

            Myt operator-(D N) const {
                return (Myt(current + N));
            }

            Myt operator+(D N) const {
                return (Myt(current - N));
            }

            Rt operator[] (D N) const {
                return (*(*this + N));
            }

            bool Lt(const Myt &Y) const {
                return (Y.current < current);
            }

            D Mi(const Myt &Y) const {
                return (Y.current - current);
            }

        protected:
            RanIt current;
        };


        template<class RanIt, class D> inline
            reverse_iterator<RanIt> operator*(D N, const reverse_iterator<RanIt> &Y) {
                return (Y + N);
            }

        template<class RanIt> inline
            typename ft::reverse_iterator<RanIt>::D operator-(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt> &Y) {
                return (X.Eq(Y));
            }
        
        template<class RanIt> inline
            bool operator!=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt> &Y) {
                return (!(X == Y));
            }

        template<class RanIt> inline
            bool operator<(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt> &Y) {
                return (X.Lt(Y));
            }

        template<class RanIt> inline
            bool operator>(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt> &Y) {
                return (Y < X);
            }

        template<class RanIt> inline
            bool operator>=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt> &Y) {
                return (!(Y < X));
            }
        
        template<class InIt, class Dist> inline
            void advance(InIt &p, Dist n) {
                p += n;
            }
        
        template<class InIt, class OutIt> inline
            OutIt copy(InIt F, InIt L, OutIt X) {
                for (; F != L; ++X, ++F)
                    *X = *F;
                return (X);
            }
        
        template<class FwdIt, class T> inline
            void fill(FwdIt F, FwdIt L, const T &X) {
                for (; F != L; ++F)
                    *F = X; 
            }

}; /* namespace ft */

#endif /* _ITERATOR_HPP_ */