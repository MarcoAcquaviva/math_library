#include "vector.h"

//Unary operator

vector &vector::operator++()
{
    x += 1;
    y += 1;
    z += 1;
    return *this;
}

vector vector::operator++(int)
{
    vector temp = *this;
    ++*this;
    return temp;
}

vector &vector::operator--()
{
    x--;
    y--;
    z--;
    return *this;
}

vector vector::operator--(int)
{
    vector temp = *this;
    --*this;
    return temp;
}

vector vector::operator-() const
{
    return vector{-x, -y, -z};
}

//Binary operator

//*Arithmetic
vector vector::operator+(const vector &other) const
{
    vector pt;
    pt.x = x + other.x;
    pt.y = y + other.y;
    pt.z = z + other.z;
    return pt;
}

vector vector::operator-(const vector &other) const
{
    vector pt;
    pt.x = x - other.x;
    pt.y = y - other.y;
    pt.z = z - other.z;
    return pt;
}

vector vector::operator*(const vector &other) const
{
    vector pt;
    pt.x = x * other.x;
    pt.y = y * other.y;
    pt.z = z * other.z;
    return pt;
}

vector vector::operator/(const vector &other) const
{
    vector pt;
    pt.x = x / other.x;
    pt.y = y / other.y;
    pt.z = z / other.z;
    return pt;
}

vector vector::operator%(const vector &other) const
{
    vector pt;
    pt.x = static_cast<int>(x) % static_cast<int>(other.x);
    pt.y = static_cast<int>(y) % static_cast<int>(other.y);
    pt.z = static_cast<int>(z) % static_cast<int>(other.z);
    return pt;
}

//POINT
vector vector::operator+(const point &other) const
{
    vector pt;
    pt.x = x + other.X();
    pt.y = y + other.Y();
    pt.z = z ;
    return pt;
}

vector vector::operator-(const point &other) const
{
    vector pt;
    pt.x = x - other.X();
    pt.y = y - other.Y();
    return pt;
}

vector vector::operator*(const point &other) const
{
    vector pt;
    pt.x = x * other.X();
    pt.y = y * other.Y();
    return pt;
}

vector vector::operator/(const point &other) const
{
    vector pt;
    pt.x = x / other.X();
    pt.y = y / other.Y();
    return pt;
}

vector vector::operator%(const point &other) const
{
    vector pt;
    pt.x = static_cast<int>(x) % static_cast<int>(other.X());
    pt.y = static_cast<int>(y) % static_cast<int>(other.Y());
    return pt;
}

//FLOAT

vector vector::operator+(const float n) const
{
    vector pt;
    pt.x = x + n;
    pt.y = y + n;
    pt.z = z + n;
    return pt;
}

vector vector::operator-(const float n) const
{
    vector pt;
    pt.x = x - n;
    pt.y = y - n;
    pt.z = z - n;
    return pt;
}

vector vector::operator*(const float n) const
{
    vector pt;
    pt.x = x * n;
    pt.y = y * n;
    pt.z = z * n;
    return pt;
}

vector vector::operator/(const float n) const
{
    vector pt;
    pt.x = x / n;
    pt.y = y / n;
    pt.z = z / n;
    return pt;
}

vector vector::operator%(const int n) const
{
    vector pt;
    pt.x = static_cast<int>(x) % n;
    pt.y = static_cast<int>(y) % n;
    pt.z = static_cast<int>(z) % n;
    return pt;
}

//*Relational
bool vector::operator<(const vector &other) const
{
    return x < other.x && y < other.y && z < other.z;
}

bool vector::operator<=(const vector &other) const
{
    return x <= other.x && y <= other.y && z <= other.z;
}

bool vector::operator>(const vector &other) const
{
    return x > other.x && y > other.y && z > other.z;
}

bool vector::operator>=(const vector &other) const
{
    return x >= other.x && y >= other.y && z >= other.z;
}

bool vector::operator==(const vector &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool vector::operator!=(const vector &other) const
{
    return !(*this == other);
}

//VECTOR
bool vector::operator<(const point &other) const
{
    return x < other.X() && y < other.Y() ;
}

bool vector::operator<=(const point &other) const
{
    return x <= other.X() && y <= other.Y() ;
}

bool vector::operator>(const point &other) const
{
    return x > other.X() && y > other.Y() ;
}

bool vector::operator>=(const point &other) const
{
    return x >= other.X() && y >= other.Y ();
}

bool vector::operator==(const point &other) const
{
    return x == other.X() && y == other.Y() ;
}

bool vector::operator!=(const point &other) const
{
    return !(*this == other);
}


//FLOAT

bool vector::operator<(const float n) const
{
    return x < n && y < n && z < n;
}

bool vector::operator<=(const float n) const
{
    return x <= n && y <= n && z <= n;
}

bool vector::operator>(const float n) const
{
    return x > n && y > n && z > n;
}

bool vector::operator>=(const float n) const
{
    return x >= n && y >= n && z >= n;
}

bool vector::operator==(const float n) const
{
    return x == n && y == n && z == n;
}

bool vector::operator!=(const float n) const
{
    return !(*this == n);
}

//*Logical
//Best practice is don't override this.

//*Bitwise
vector vector::operator<<(size_t n) const
{
    vector pt;
    pt.x = static_cast<int>(x) << n;
    pt.y = static_cast<int>(y) << n;
    pt.z = static_cast<int>(z) << n;
    return pt;
}

vector vector::operator>>(size_t n) const
{
    vector pt;
    pt.x = static_cast<int>(x) >> n;
    pt.y = static_cast<int>(y) >> n;
    pt.z = static_cast<int>(z) >> n;
    return pt;
}

//*Assignment

vector &vector::operator=(const vector &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

vector &vector::operator+=(const vector &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

vector &vector::operator-=(const vector &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

vector &vector::operator*=(const vector &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

vector &vector::operator/=(const vector &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

vector vector::operator%=(const vector &other)
{


    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);
    int tmp_z = static_cast<int>(z);

    tmp_x %= static_cast<int>(other.x);
    tmp_y %= static_cast<int>(other.y);
    tmp_z %= static_cast<int>(other.z);

    x = tmp_x;
    y = tmp_y;
    z = tmp_z;

    return *this;
}

//POINT 


vector &vector::operator=(const point &other)
{
    x = other.X();
    y = other.Y();
    return *this;
}

vector &vector::operator+=(const point &other)
{
    x += other.X();
    y += other.Y();
    return *this;
}

vector &vector::operator-=(const point &other)
{
    x -= other.X();
    y -= other.Y();
    return *this;
}

vector &vector::operator*=(const point &other)
{
    x *= other.X();
    y *= other.Y();
    return *this;
}

vector &vector::operator/=(const point &other)
{
    x /= other.X();
    y /= other.Y();
    return *this;
}

vector vector::operator%=(const point &other)
{


    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);
    int tmp_z = static_cast<int>(z);

    tmp_x %= static_cast<int>(other.X());
    tmp_y %= static_cast<int>(other.Y());

    x = tmp_x;
    y = tmp_y;
    z = tmp_z;

    return *this;
}

//FLOAT

vector &vector::operator=(const float n)
{
    x = n ;
    y = n ;
    z = n ;
    return *this;
}

vector &vector::operator+=(const float n)
{
    x += n ;
    y += n ;
    z += n ;
    return *this;
}

vector &vector::operator-=(const float n)
{
    x -= n ;
    y -= n ;
    z -= n ;
    return *this;
}

vector &vector::operator*=(const float n)
{
    x *= n ;
    y *= n ;
    z *= n ;
    return *this;
}

vector &vector::operator/=(const float n)
{
    x /= n ;
    y /= n ;
    z /= n ;
    return *this;
}

vector vector::operator%=(const int n)
{

    int tmp_x = static_cast<int>(x);
    int tmp_y = static_cast<int>(y);
    int tmp_z = static_cast<int>(z);

    tmp_x %= n ;
    tmp_y %= n ;
    tmp_z %= n ;

    x = tmp_x;
    y = tmp_y;
    z = tmp_z;

    return *this;
}

//other

float vector::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else if (index == 2)
        return z;
    return 0;
}