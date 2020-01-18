#pragma once

#include <iostream>
#include <string>

using namespace std;

struct matrix
{
    matrix() = default;

    matrix(int i_, int j_, float initial)
    {
        if (i_ >= 0 && j_ >= 0)
        {
            m_row = i_;
            m_col = j_;

            for (size_t row = 0; row < m_row; row++)
            {
                for (size_t col = 0; col < m_col; col++)
                {
                    this->m_matrix[row][col] = initial;
                }
            }
        }
    }

    matrix(const matrix &other) {}

    ~matrix() {}

    //Binary operator

    //*Arithmetic
    matrix operator+(const matrix &other) const;

    matrix operator-(const matrix &other) const;

    matrix operator*(const matrix &other) const;

    //By matrix inversion TODO
    matrix operator/(const matrix &other) const;

    //FLOAT
    matrix operator+(const float) const;

    matrix operator-(const float) const;

    matrix operator*(const float)const;

    matrix operator/(const float) const;

    //*Assignment

    matrix &operator=(const matrix &other);

    matrix &operator+=(const matrix &other);

    matrix &operator-=(const matrix &other);

    // By matrix inversion TODO
    matrix &operator/=(const matrix &other);

    //FLOAT
    matrix &operator=(const float);

    matrix &operator+=(const float);

    matrix &operator-=(const float);

    matrix &operator*=(const float);

    matrix &operator/=(const float);


    //other

    float operator()(const int row, const int col) const;

    int Row() const { return m_row; }
    int Col() const { return m_col; }

    void print()
    {
        for (int i = 0; i < m_row; i++)
            for (int j = 0; j < m_col; j++)
            {
                cout << name << "[" << i << "][" << j << "]: ";
                cout << m_matrix[i][j] << endl;
            }
    }

    matrix &identity()
    {
        if (m_row == m_col)
        {
            for (size_t row = 0; row < m_row; row++)
            {
                for (size_t col = 0; col < m_col; col++)
                {
                    if (col == row)
                        continue;
                    m_matrix[row][col] = 0;
                }
            }
        }

        return *this;
    }

    bool is_m_size_equal_to(const matrix &other)const{
        return m_col == other.m_col && m_row == other.m_row;
    }

    bool square()const{
        return m_col == m_row;
    }

public:
    string name;
    float m_matrix[100][100];

private:
    int m_row, m_col;
};
