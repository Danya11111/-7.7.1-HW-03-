#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <algorithm> // for std::copy_n
using namespace std;

class Bad_Range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ОШИБКА: Вне диапазона контейнера.";
    }
};

template <typename X> class IntArray
{
private:
    X m_length{};
    X* m_data{};

public:
    IntArray() = default;

    IntArray(X length) : m_length{ length }{
        
        if (length <= 0) {
            throw "Bad_length";
        }

        if (length > 0)
            m_data = new X[length] {};
    }

    ~IntArray() {
        delete[] m_data;
    }

    IntArray(const IntArray& a) : IntArray(a.getLength())
    {
        copy_n(a.m_data, m_length, m_data);
    }

    IntArray& operator=(const IntArray& a)
    {
        if (&a == this)
            return *this;
        reallocate(a.getLength());
        copy_n(a.m_data, m_length, m_data); // copy the elements
        return *this;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    auto& operator[](int index)
    {
        if (index < 0 && index >= m_length) {
            throw "Bad_index";
        }
        return m_data[index];
    }

    void reallocate(int newLength)
    {
        erase();
        if (newLength <= 0)
            return;
        m_data = new X[newLength];
        m_length = newLength;
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data{ new int[newLength] };

        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
            copy_n(m_data, elementsToCopy, data);
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(X value, int index)
    {
        if (index < 0 && index > m_length) {
            throw "Bad_range";
        }

        X* data{ new X[m_length + 1] };

        copy_n(m_data, index, data);

        data[index] = value;

        copy_n(m_data + index, m_length - index, data + index + 1);

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void remove(int index)
    {
        if (index < 0 && index >= m_length) {
            throw "Bad_range";
        }
        if (m_length == 1)
        {
            erase();
            return;
        }

        int* data{ new int[m_length - 1] };

        copy_n(m_data, index, data);

        copy_n(m_data + index + 1, m_length - index - 1, data + index);

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void insertAtBeginning(X value) { insertBefore(value, 0); }
    void insertAtEnd(X value) { insertBefore(value, m_length); }

    X getLength() const { return m_length; }

    void vivod_arr() {
        for (int i = 0; i < m_length; i++) {
            cout << m_data[i] << ' ';
        }
        cout << endl;
    }

    void set_value(int index, X value) {
        m_data[index] = value;
    }
    bool prowerka(X value) {
        for (int i = 0; i < m_length; i++) {
            if (m_data[i] == value) {
                return 1;
            }
        }
        return 0;
    }
};

#endif