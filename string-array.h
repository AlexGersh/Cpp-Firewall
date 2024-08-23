#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "generic-string.h"
#include "string.h"
#include <algorithm>
#include <iostream>
#include <vector>
class StringArray {
  private:
    std::vector<GenericString *> vec;

  public:
    // C'tor D'tor
    StringArray();
    StringArray(const StringArray &);
    ~StringArray();

    StringArray &operator=(const StringArray &);

    // getter and
    int size();
    // adding to end
    void Add(GenericString &);
    void clear();
    GenericString &operator[](int);
};

#endif
