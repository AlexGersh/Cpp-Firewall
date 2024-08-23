#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "generic-string.h"
#include "string.h"
#include <algorithm>
#include <iostream>
#include <vector>

#define SIZE 4
class StringArray {
  private:
     GenericString*  gs_arr[SIZE];

  public:
    // C'tor D'tor
    StringArray();
    StringArray(const StringArray &);
    ~StringArray();

    StringArray &operator=(const StringArray &);

    // getter and
    int size() const ;
    // adding to end
    void add(GenericString *);
    GenericString* operator[](int);
};

#endif
