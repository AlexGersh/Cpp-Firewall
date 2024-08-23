#include "string-array.h"

StringArray::StringArray() : vec() {};

StringArray::StringArray(const StringArray &other) {
    /* GenericString* gs;
     //copy each constrcutor
     for( GenericString* ptr :other.vec)
     {
         gs=new String(ptr->as_string());
         vec.push_back(gs);
     }
     */

    this->vec = other.vec;
}

StringArray::~StringArray() { vec.clear(); }

StringArray &StringArray::operator=(const StringArray &other) {
    // this->clear();
    this->vec = other.vec;
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

void StringArray::clear() {

    for (GenericString *ptr : vec) {
        delete ptr;
    }
    this->vec.clear();
}