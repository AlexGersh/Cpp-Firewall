#include "string-array.h"

StringArray::StringArray() : vec() {};

StringArray::StringArray(const StringArray &other) { this->vec = other.vec; }

StringArray::~StringArray() 
{
}

StringArray& StringArray::operator=(const StringArray& other)
{
    this->vec.clear();
    this->vec=other.vec;
    return *this;
}

int StringArray::size() { return this->vec.size(); }

void StringArray::Add(GenericString &g) { this->vec.push_back(&g); }

GenericString &StringArray::operator[](int i) {

    if (i > this->vec.size())
        std::cout << "Out of Boundary" << std::endl;

    GenericString &rt = *(this->vec[i]);
    return rt;
}

void StringArray::clear()
{
    
    for( GenericString*  ptr : vec)
    {
        delete ptr;
    }
    vec.clear();
}