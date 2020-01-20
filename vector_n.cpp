#include "vector_n.h"

//Unary operator

vector_n &vector_n::operator++()
{
    for (size_t i = 0; i < size; i++)
    {        
       ++v_array[i];
    }

    return *this;
}

vector_n &vector_n::operator++(int)
{
    for (size_t i = 0; i < size; i++)
    {        
        v_array[i]++;
    }

    return *this;
}

vector_n &vector_n::operator--()
{

    for (size_t i = 0; i < size; i++)
    {        
        --v_array[i];
    }

    return *this;
}

vector_n &vector_n::operator--(int)
{
    for (size_t i = 0; i < size; i++)
    {        
        v_array[i]--;
    }

    return *this;
}

vector_n vector_n::operator-() const
{
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] = -tmp_array[i];
    }

    memcpy(tmp_vector_n.v_array,tmp_array,size*sizeof(float));

    return tmp_vector_n;
}

//Binary operator

//*Arithmetic
vector_n vector_n::operator+(const vector_n &other) const
{
    if(size == other.size){
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] += other.v_array[i];
        tmp_vector_n.v_array[i] = static_cast<float>(tmp_array[i]);
    }

    return tmp_vector_n;

    }

    return *this;
}

vector_n vector_n::operator-(const vector_n &other) const
{
    if(size == other.size){
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] -= other.v_array[i];
        tmp_vector_n.v_array[i] = static_cast<float>(tmp_array[i]);
    }

    return tmp_vector_n;

    }

    return *this;
    
}

vector_n vector_n::operator*(const vector_n &other) const
{
     if (size == other.size)
    {
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] *= other.v_array[i];
        tmp_vector_n.v_array[i] = static_cast<float>(tmp_array[i]);
    }

    return tmp_vector_n;

    }

    return *this;
}

vector_n vector_n::operator/(const vector_n &other) const
{
         if (size == other.size)
    {
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] /= other.v_array[i];
        tmp_vector_n.v_array[i] = static_cast<float>(tmp_array[i]);
    }

    return tmp_vector_n;

    }

    return *this;
}

vector_n vector_n::operator%(const vector_n &other) const
{
     if (size == other.size)
    {
        vector_n tmp_vector_n{size, 0};
        int *tmp_array = new int[size];
        int *tmp_other = new int[other.size];


        for (size_t i = 0; i < size; i++)
        {
            tmp_array[i] = static_cast<int>(v_array[i]);
            tmp_other[i] = static_cast<int>(other.v_array[i]);
            tmp_array[i] %= tmp_other[i];
        }

        memcpy(tmp_vector_n.v_array,tmp_array,size*sizeof(float));

        return tmp_vector_n;
    }

    return *this;
}

//FLOAT

vector_n vector_n::operator+(const float n) const
{
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_vector_n.v_array[i] = tmp_array[i] += n;
    }

    return tmp_vector_n;
}

vector_n vector_n::operator-(const float n) const
{
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_vector_n.v_array[i] = tmp_array[i] -= n;
    }

    return tmp_vector_n;
}

vector_n vector_n::operator*(const float n) const
{
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_vector_n.v_array[i] = tmp_array[i] *= n;
    }

    return tmp_vector_n;
}

vector_n vector_n::operator/(const float n) const
{
    vector_n tmp_vector_n{size, 0};
    float *tmp_array = new float[size];
    memcpy(tmp_array, v_array, size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        tmp_vector_n.v_array[i] = tmp_array[i] /= n;
    }

    return tmp_vector_n;
}

vector_n vector_n::operator%(const int n) const
{
        vector_n tmp_vector_n{size, 0};
        int *tmp_array = new int[size];

        for (size_t i = 0; i < size; i++)
        {
            tmp_array[i] = static_cast<int>(v_array[i]);
            tmp_vector_n.v_array[i] = tmp_array[i] % n;
        }    

    return tmp_vector_n;
}

//*Relational

/// Manage error excemption if size doesn't match up
bool vector_n::operator<(const vector_n &other) const
{
    if(size == other.size){
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] > other.v_array[i])
            return false;
    }
    }

    return true;

}

bool vector_n::operator<=(const vector_n &other) const
{
    if(size == other.size){
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] > other.v_array[i])
            return false;
    }

    }
    return true;

}

bool vector_n::operator>(const vector_n &other) const
{
        if(size == other.size){
        
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] < other.v_array[i])
            return false;
    }
    }

    return true;
}

bool vector_n::operator>=(const vector_n &other) const
{
        if(size == other.size){
        
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] < other.v_array[i])
            return false;
    }

    }
    return true;
}

bool vector_n::operator==(const vector_n &other) const
{
        if(size == other.size){
        
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] != other.v_array[i])
            return false;
    }

    }
    return true;
}

bool vector_n::operator!=(const vector_n &other) const
{
    return !(*this == other);
}

//FLOAT

bool vector_n::operator<(const float n) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] > n)
            return false;
    }

    return true;
}

bool vector_n::operator<=(const float n) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] >= n)
            return false;
    }

    return true;
}

bool vector_n::operator>(const float n) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] < n)
            return false;
    }

    return true;
}

bool vector_n::operator>=(const float n) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] <= n)
            return false;
    }

    return true;
}

bool vector_n::operator==(const float n) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (v_array[i] != n)
            return false;
    }

    return true;
}

bool vector_n::operator!=(const float n) const
{
    return !(*this == n);
}

//*Logical
//Best practice is don't override this.

// //*Bitwise
// vector_n vector_n::operator<<(size_t n) const
// {
//     vector_n tmp_vector_n{size, 0};
//     int *tmp_array = new int[size];

//     for (size_t i = 0; i < size; i++)
//     {
//         tmp_array[i] = static_cast<int>(v_array[i]);
//         tmp_vector_n.v_array[i] = tmp_array[i] << n;
//     }

//     return tmp_vector_n;
// }

// vector_n vector_n::operator>>(size_t n) const
// {
//     vector_n tmp_vector_n{size, 0};
//     int *tmp_array = new int[size];
//     memcpy(tmp_array, v_array, size * sizeof(int));

//     for (size_t i = 0; i < size; i++)
//     {
//         tmp_vector_n.v_array[i] = tmp_array[i] >> n;
//     }

//     return tmp_vector_n;
// }

//*Assignment

vector_n &vector_n::operator=(const vector_n &other)
{
    if (size == other.size)
        for (size_t i = 0; i < size; i++)
        {
            v_array[i] = other.v_array[i];
        }

    return *this;
}

vector_n &vector_n::operator+=(const vector_n &other)
{
    if (size == other.size)
        for (size_t i = 0; i < size; i++)
        {
            v_array[i] += other.v_array[i];
        }

    return *this;
}

vector_n &vector_n::operator-=(const vector_n &other)
{
    if (size == other.size)
        for (size_t i = 0; i < size; i++)
        {
            v_array[i] -= other.v_array[i];
        }

    return *this;
}

vector_n &vector_n::operator*=(const vector_n &other)
{
    if (size == other.size)
        for (size_t i = 0; i < size; i++)
        {
            v_array[i] *= other.v_array[i];
        }

    return *this;
}

vector_n &vector_n::operator/=(const vector_n &other)
{
    if (size == other.size)
        for (size_t i = 0; i < size; i++)
        {
            v_array[i] /= other.v_array[i];
        }

    return *this;
}

vector_n vector_n::operator%=(const vector_n &other)
{
    if (size == other.size)
    {
        int *tmp_array = new int[size];
        int *tmp_other = new int[other.size];

        for (size_t i = 0; i < size; i++)
        {
            tmp_array[i] = static_cast<int>(v_array[i]);
            tmp_other[i] = static_cast<int>(other.v_array[i]);
            tmp_array[i] %= tmp_other[i];
        }

        memcpy(v_array, tmp_array, size * sizeof(float));
    }

    return *this;
}

//FLOAT

vector_n &vector_n::operator=(const float n)
{
    for (size_t i = 0; i < size; i++)
    {
        v_array[i] = n;
    }

    return *this;
}

vector_n &vector_n::operator+=(const float n)
{
    for (size_t i = 0; i < size; i++)
    {
        v_array[i] += n;
    }
    return *this;
}

vector_n &vector_n::operator-=(const float n)
{
    for (size_t i = 0; i < size; i++)
    {
        v_array[i] -= n;
    }
    return *this;
}

vector_n &vector_n::operator*=(const float n)
{
    for (size_t i = 0; i < size; i++)
    {
        v_array[i] *= n;
    }
    return *this;
}

vector_n &vector_n::operator/=(const float n)
{
    for (size_t i = 0; i < size; i++)
    {
        v_array[i] /= n;
    }

    return *this;
}

vector_n vector_n::operator%=(const int n)
{

    int *tmp_array = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        tmp_array[i] = static_cast<int>(v_array[i]);
        tmp_array[i] %= n;
    }

    memcpy(v_array, tmp_array, size * sizeof(float));

    return *this;
}

//other

float vector_n::operator[](int index) const
{
    if (index >= 0 && index < this->size)
    {
        return v_array[index];
    }

    return 0;
}