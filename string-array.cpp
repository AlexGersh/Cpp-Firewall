#include "string-array.h"


StringArray::StringArray():vec(){};

StringArray::StringArray(const StringArray& other){
    this->vec=other.vec;
}

StringArray::~StringArray(){}

int StringArray::size()
{
    return this->vec.size();
}

void StringArray::Add(const GenericString& g)
{
    this->vec.push_back(g);
}



GenericString& StringArray::operator[](int i)
{
    //l_front will be iterator
    return *(this->vec[i]);
}



int main()
{


    return 0;
}

