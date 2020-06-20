#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstdint>
#include <vector>

namespace me {
template <typename T>
class Matrix
{
public:
    using size_type = int64_t;
    using value_type = T;

    Matrix(size_type num_of_rows, size_type num_of_cols)
        : m_data(num_of_rows * num_of_cols)
        , m_rows(num_of_rows)
        , m_cols(num_of_cols)
    {
    }

    const value_type&
    at(size_type r, size_type c) const
    {
        return m_data[r * m_cols + c];
    }

    value_type&
    at(size_type r, size_type c)
    {
        return m_data[r * m_cols + c];
    }

    size_type
    num_of_rows() const
    {
        return m_rows;
    }

    size_type
    num_of_cols() const
    {
        return m_cols;
    }

    auto
    begin()
    {
        return m_data.begin();
    }
    auto
    end()
    {
        return m_data.end();
    }

    auto
    begin() const
    {
        return m_data.cbegin();
    }
    auto
    end() const
    {
        return m_data.cend();
    }

private:
    std::vector<T> m_data;
    size_type m_rows;
    size_type m_cols;
};
};
#endif
