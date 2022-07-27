// template containter header
#ifndef _ARR_HPP_
#define _ARR_HPP_
#include <iosfwd>
#include <cassert> // для assert()

template <class T>
class Array 
{
    int m_length;
    T *m_data;

public:

    void init(int length)
    {
        if (length > 0)
            m_data = new T[length];
        else
            m_data = nullptr;
    }

    Array(): m_length(0), m_data(nullptr) {}

    Array(int length): m_length(length) { init(length); }

    ~Array() { delete[] m_data; }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int get_length() { return m_length; }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    void reallocate(int new_length)
    {
        erase();
        if (new_length == 0)
            return;
        m_length = new_length;
        init(new_length);
    }

    void resize(int new_length)
    {
        if (new_length == m_length)
            return;

        if (new_length <= 0)
        {
            erase();
            return;
        }

        int *data = new T[new_length];

        int elementsToCopy = (new_length > m_length) ? m_length : new_length;

        for (int i = 0; i < elementsToCopy; i++)
            data[i] = m_data[i];

        delete [] m_data;

        m_data = data;
        m_length = new_length;
    }
};

#endif /* _ARRINT_HPP_ */

