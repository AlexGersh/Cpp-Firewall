#include "string-array.h"

StringArray::StringArray() {
    for (int i=0;i<SIZE;i++)
    {
        gs_arr[i]=nullptr;
    }
};

StringArray::StringArray(const StringArray &other) {
    for (int i=0;i<SIZE;i++)
    {
        gs_arr[i]=make_string(other.gs_arr[i]->as_string().get_data());
    }    
}

StringArray::~StringArray() {
    for(int i=0;i<SIZE;i++)
    {
        delete dynamic_cast<String*>(gs_arr[i]);    
    }

}


StringArray &StringArray::operator=(const StringArray &other) {
    
    for(int i=0;i<other.size();i++)
    {
        delete gs_arr[i];
        gs_arr[i]=make_string(other.gs_arr[i]->as_string().get_data());
    }
    
    return *this;
}

int StringArray::size() const {
    
    int size=SIZE;
    for(int i=0;i<SIZE;i++)
    {
        if(gs_arr[i]==nullptr)
        {
            size=i;
            break;
        }
    }

    return size;
}

void StringArray::add(GenericString* g) {

    gs_arr[size()]=g;
}

GenericString* StringArray::operator[](int i) {

    if (i > size())
    {
        std::cout << "Out of Boundary" << std::endl;
        return nullptr;
    }

    return gs_arr[i];
}


    