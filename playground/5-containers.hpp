// containter header
#ifndef _ARRINT_HPP_
#define _ARRINT_HPP_
#include <iosfwd>
#include <cassert> // для assert()


class ArrayInt 
{
    int m_length;
    int *m_data;

public:

    void init(int length)
    {
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ArrayInt(): m_length(0), m_data(nullptr) {}

    ArrayInt(int length): m_length(length) { init(length); }

    ArrayInt(const ArrayInt &arr): m_length(arr.m_length) {
        init(arr.m_length);
        if (m_data == nullptr)
            return;
        for (size_t i = 0; i < arr.m_length; i++)
        {
            m_data[i] = arr.m_data[i];
        }
    }

    ~ArrayInt() { delete[] m_data; }

    int& operator[](int index)
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

        int *data = new int[new_length];

        int elementsToCopy = (new_length > m_length) ? m_length : new_length;

        for (int i = 0; i < elementsToCopy; i++)
            data[i] = m_data[i];

        delete [] m_data;

        m_data = data;
        m_length = new_length;
    }
};

#endif /* _ARRINT_HPP_ */