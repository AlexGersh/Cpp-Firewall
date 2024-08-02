#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "generic-string.h"
#include <list>

class StringArray {
    private:
    list<GenericString> list;

    public:

        //C'tor D'tor
        StringArray();
        StringArray(const &StringArray);
        ~StringArray();

        //getter and 
        int get_size();
        //adding to end
        void Add(GenericString&);
        
        //remove specific
        void Remove(GenericString&);

        GenericString operator[](int);
        
}



#endif
