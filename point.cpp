#include "point.h"
//Unary operator

point &point::operator++()
{
    x += 1;
    y += 1;
    return *this;
}

point point::operator++(int)
{
    point temp = *this;
    ++*this;
    return temp;
}
point &point::operator--()
{
    x--;
    y--;
    return *this;
}
point point::operator--(int)
{
    point temp = *this;
    --*this;
    return temp;
}
point point::operator-() const
{
    return point{-x, -y};
}

//Binary operator

//*Arithmetic
point point::operator+(const point &other) const
{
    point pt;
    pt.x = x + other.x;
    pt.y = y + other.y;
    return pt;
}

point point::operator-(const point &other) const
{
    point pt;
    pt.x = x - other.x;
    pt.y = y - other.y;
    return pt;
}

point point::operator*(const point &other) const
{
    point pt;
    pt.x = x * other.x;
    pt.y = y * other.y;
    return pt;
}

point point::operator/(const point &other) const
{
    point pt;
    if (other.x != 0 && other.y != 0)
    {
        pt.x = x / other.x;
        pt.y = y / other.y;
    }
    return pt;
}

point point::operator%(const point &other) const
{
    point pt;

    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);

    tmp_x %= static_cast<int>(other.x);
    tmp_y %= static_cast<int>(other.y);

    pt.x = tmp_x;
    pt.y = tmp_y;

    return pt;
}

// btw float

point point::operator+(const float n) const
{
    point pt;
    pt.x = x + n;
    pt.y = y + n;
    return pt;
}

point point::operator-(const float n) const
{
    point pt;
    pt.x = x - n;
    pt.y = y - n;
    return pt;
}

point point::operator*(const float n) const
{
    point pt;
    pt.x = x * n;
    pt.y = y * n;
    return pt;
}

point point::operator/(const float n) const
{
    point pt;
    if (n != 0)
    {
        pt.x = x / n;
        pt.y = y / n;
    }
    return pt;
}

point point::operator%(const int n) const
{
    point pt;

    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);

    tmp_x %= n;
    tmp_y %= n;

    pt.x = tmp_x;
    pt.y = tmp_y;

    return pt;
}

//*Relational
bool point::operator<(const point &other) const
{
    return x < other.x && y < other.y;
}

bool point::operator<=(const point &other) const
{
    return x <= other.x && y <= other.y;
}

bool point::operator>(const point &other) const
{
    return x > other.x && y > other.y;
}

bool point::operator>=(const point &other) const
{
    return x >= other.x && y >= other.y;
}

bool point::operator==(const point &other) const
{
    return x == other.x && y == other.y;
}

bool point::operator!=(const point &other) const
{
    return !(*this == other);
}

//FLOAT

bool point::operator<(const float n) const
{
    return x < n && y < n;
}

bool point::operator<=(const float n) const
{
    return x <= n && y <= n;
}

bool point::operator>(const float n) const
{
    return x > n && y > n;
}

bool point::operator>=(const float n) const
{
    return x >= n && y >= n;
}

bool point::operator==(const float n) const
{
    return x == n && y == n;
}

bool point::operator!=(const float n) const
{
    return !(*this == n);
}

//*Logical
//Best practice is don't override this.

//*Bitwise
point point::operator<<(size_t n) const
{
    point pt;
    pt.x = static_cast<int>(x) << n;
    pt.y = static_cast<int>(y) << n;
    return pt;
}

point point::operator>>(size_t n) const
{
    point pt;
    pt.x = static_cast<int>(x) >> n;
    pt.y = static_cast<int>(y) >> n;
    return pt;
}

//*Assignment

point &point::operator=(const point &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

point &point::operator+=(const point &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

point &point::operator-=(const point &other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

point &point::operator*=(const point &other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

point &point::operator/=(const point &other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

point point::operator%=(const point &other)
{

    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);

    tmp_x %= static_cast<int>(other.x);
    tmp_y %= static_cast<int>(other.y);

    x = tmp_x;
    y = tmp_y;

    return *this;
}

//FLOAT

point &point::operator=(const float n)
{
    x = n;
    y = n;
    return *this;
}

point &point::operator+=(const float n)
{
    x += n;
    y += n;
    return *this;
}

point &point::operator-=(const float n)
{
    x -= n;
    y -= n;
    return *this;
}

point &point::operator*=(const float n)
{
    x *= n;
    y *= n;
    return *this;
}

point &point::operator/=(const float n)
{
    x /= n;
    y /= n;
    return *this;
}

point point::operator%=(const int n)
{
    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);

    tmp_x %= n;
    tmp_y %= n;

    x = tmp_x;
    y = tmp_y;

    return *this;
}

//other

float point::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    return 0;
}
