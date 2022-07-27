// vector template header
#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <iosfwd>
#include <memory>
#include <stdexcept>

namespace ft {

    // Vector_val template class 
    template<class T, class A>
        class Vector_val {
    protected:

        Vector_val(A Al = A()): Alval(Al) {}
        typedef typename A::template rebind<T>::other Alty;
        Alty Alval;

        };

    // vector template class
    template<class T, class Ax = std::allocator<T>>
        class vector: public Vector_val<T, Ax> {
    public:

        typedef ft::vector<T, Ax>               Myt;
        typedef ft::Vector_val<T, Ax>           Mybase;
        typedef typename Mybase::Alty           A; 
        typedef A                               allocator_type;
        typedef typename A::size_type           size_type;
        typedef typename A::difference_type     difference_type;
        typedef typename A::pinter              Tptr;
        typedef typename A::const_pinter        Ctptr;
        typedef Tptr                            pointer;
        typedef Ctptr                           const_pointer;
        typedef typename A::reference           reference; 
        typedef typename A::const_reference     const_reference; 
        typedef typename A::value_type          value_type; 
        typedef Ptrit<value_type, difference_type, Tptr, reference, Tptr, reference>        iterator;
        typedef Ptrit<value_type, difference_type, Ctptr, const_reference, Tptr, reference> const_iterator;
        typedef std::reverse_iterator<iterator>                                             reverse_iterator;
        typedef std::reverse_iterator<const_iterator>                                       const_reverse_iterator;

        vector(): Mybase() { 
            Buy(0); 
        }

        explicit vector(const A& Al): Mybase(Al) { 
            Buy(0); 
        }

        explicit vector(size_type N): Mybase() { 
            if (Buy(N)) 
                Last = Ufill(First, N, T());
        }

        vector(size_type N, const T &V): Mybase() {
            if (Buy(N)) 
                Last = Ufill(First, N, V);
        }

        vector(size_type N, const T &V, const A &Al): Mybase(Al) {
            if (Buy(N)) 
                Last = Ufill(First, N, V);
        }

        vector(const Myt &X): Mybase(X.Alval) {
            if (Buy(X.size()))
                Last = Ucopy(X.begin(), X.end(), first);
        }

        template<class It>
            vector(It F, It L): Mybase() {
                Construct(F, L, Iter_cat(F));
            }

        template<class It>
            void Construct(It F, It L, Int_iterator_tag) {
                size_type N = (size_type)F;
                if (Buy(N))
                    Last = Ufill(First, N, (T)L);
            }

        template<class It>
            void Construct(It F, It L, input_iterator_tag) {
                Buy(N);
                insert(begin(), F, L);
            }
        
        ~vector() {
            Clear();
        }

    protected:

        bool Buy(size_type N) {
            Frist = 0;
            Last = 0;
            End = 0;
        }
        
    };
}; /* namespace ft */

#endif /* _VECTOR_HPP_ */