#include "matrix.h"

//other
float matrix::operator()(const int row, const int col) const
{
    return this->m_matrix[row][col];
}

//Binary operator

//*Arithmetic
matrix matrix::operator+(const matrix &other) const
{
    matrix tmp(m_row, m_col, -1);
    if (is_m_size_equal_to(other))
    {

        for (size_t row = 0; row < m_row; row++)
        {
            for (size_t col = 0; col < m_col; col++)
            {
                tmp.m_matrix[row][col] = this->m_matrix[row][col] + other(row, col);
            }
        }
    }

    return tmp;
}

matrix matrix::operator-(const matrix &other) const
{
    matrix tmp(m_row, m_col, -1);
    if (is_m_size_equal_to(other))
    {
        for (size_t row = 0; row < m_row; row++)
        {
            for (size_t col = 0; col < m_col; col++)
            {
                tmp.m_matrix[row][col] = this->m_matrix[row][col] - other(row, col);
            }
        }
    }

    return tmp;
}

matrix matrix::operator*(const matrix &other) const
{

    if (m_row == other.m_col)
    {
        matrix tmp(m_col, other.m_row, -1);
        for (size_t row = 0; row < tmp.m_row; row++)
        {
            for (size_t col = 0; col < tmp.m_col; col++)
            {
                float mul = 0.0f;
                for (size_t k = 0; k < m_row; k++)
                {
                    mul += m_matrix[k][col] * other(row, k);
                }
                tmp.m_matrix[row][col] = mul;
            }
        }
        return tmp;
    }
    else if (m_col == other.m_row)
    {
        matrix tmp(m_row, other.m_col, -1);
        for (size_t row = 0; row < tmp.m_row; row++)
        {
            for (size_t col = 0; col < tmp.m_col; col++)
            {
                float mul = 0.0f;
                for (size_t k = 0; k < m_col; k++)
                {
                    mul += m_matrix[row][k] * other(k, col);
                }
                tmp.m_matrix[row][col] = mul;
            }
        }
        return tmp;
    }
    matrix tmp = *this;
    return tmp;
}

matrix matrix::operator/(const matrix &other) const
{
    if (square() && is_m_size_equal_to(other))
    {
    }

    return *this;
}

//FLOAT
matrix matrix::operator+(const float scalar) const
{
    matrix tmp(m_row, m_col, -1);

    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            tmp.m_matrix[row][col] = this->m_matrix[row][col] + scalar;
        }
    }

    return tmp;
}

matrix matrix::operator-(const float scalar) const
{
    matrix tmp(m_row, m_col, -1);

    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            tmp.m_matrix[row][col] = this->m_matrix[row][col] - scalar;
        }
    }

    return tmp;
}

matrix matrix::operator*(const float scalar) const
{

    matrix tmp(m_col, m_row, -1);
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {

            tmp.m_matrix[row][col] = m_matrix[row][col] * scalar;
        }
    }
    return tmp;
}

matrix matrix::operator/(const float scalar) const
{

    matrix tmp(m_col, m_row, -1);
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {

            tmp.m_matrix[row][col] = m_matrix[row][col] / scalar;
        }
    }
    return tmp;
}

//*Assignment
matrix &matrix::operator=(const matrix &other)
{
    if (is_m_size_equal_to(other))
    {
        for (size_t row = 0; row < m_row; row++)
        {
            for (size_t col = 0; col < m_col; col++)
            {
                this->m_matrix[row][col] = other(row, col);
            }
        }
    }
    return *this;
}

matrix &matrix::operator+=(const matrix &other)
{
    if (is_m_size_equal_to(other))
    {

        for (size_t row = 0; row < m_row; row++)
        {
            for (size_t col = 0; col < m_col; col++)
            {
                this->m_matrix[row][col] += other(row, col);
            }
        }
    }

    return *this;
}

matrix &matrix::operator-=(const matrix &other)
{
    if (is_m_size_equal_to(other))
    {

        for (size_t row = 0; row < m_row; row++)
        {
            for (size_t col = 0; col < m_col; col++)
            {
                this->m_matrix[row][col] -= other(row, col);
            }
        }
    }

    return *this;
}


//FLOAT

matrix &matrix::operator=(const float scalar)
{
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            this->m_matrix[row][col] = scalar;
        }
    }
    return *this;
}

matrix &matrix::operator+=(const float scalar)
{
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            m_matrix[row][col] += scalar;
        }
    }
    return *this;
}

matrix &matrix::operator-=(const float scalar)
{
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            m_matrix[row][col] -= scalar;
        }
    }
    return *this;
}

matrix &matrix::operator*=(const float scalar)
{
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            m_matrix[row][col] *= scalar;
        }
    }
    return *this;
}

matrix &matrix::operator/=(const float scalar)
{
    for (size_t row = 0; row < m_row; row++)
    {
        for (size_t col = 0; col < m_col; col++)
        {
            m_matrix[row][col] /= scalar;
        }
    }
    return *this;
}