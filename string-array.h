#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "generic-string.h"
#include <iostream>
#include <vector>
#include <algorithm>
class StringArray {
  private:
    std::vector<GenericString *> vec;

  public:
    // C'tor D'tor
    StringArray();
    StringArray(const StringArray &);
    ~StringArray();

    // getter and
    int size();
    // adding to end
    void Add(GenericString &);

    GenericString &operator[](int);
};

#endif
