#include "string.h"
#include "string-array.h"
#include <cstring>

char *String::allocate_and_copy(const char *data, int size) {
    char *str = new char[size + 1];
    strcpy(str, data);
    return str;
    // strcpy returns the poinetr to dst, we may implement by one line:
    // return strcpy(new char[size + 1], data);
}

int String::get_length() const { return length; }

const char *String::get_data() const { return data; }

String::String(const char *str = "") {
    // if no str provided, by default its an empty string and length will be 0
    length = strlen(str);
    data = String::allocate_and_copy(str, length);
}

String::String(const String &str_obj) {
    length = str_obj.get_length();
    data = String::allocate_and_copy(str_obj.get_data(), length);
}

String::~String() { delete[] data; }

String &String::operator=(const char *str) {
    length = strlen(str);
    data = String::allocate_and_copy(str, length);
    return *this;
}

bool String::operator==(const char *other) const {
    return strcmp(data, other) == 0;
}

// this shit doesnt work
//  bool String::operator==(const GenericString &other) const {
//      const String &str = as_string(other);
//      return strcmp(data, str.getData()) == 0;
//  }

const String &String::as_string() const { return *this; }

String &String::as_string() { return *this; }

// should be global
GenericString *make_string(const char *str) {

    //
}
