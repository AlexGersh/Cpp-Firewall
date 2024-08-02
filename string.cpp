#include "string.h"
#include "string-array.h"
#include <string>

char *String::allocate_and_copy(const char *data, int size) {
    char *str = new char[size + 1];
    strcpy(str, data);
    return str;
}

String::String() {
    length = 0;
    data = NULL;
}

String::String(const char *str) {
    length = strlen(str);
    data = String::allocate_and_copy(str, length + 1);
}

String::String(const String &str) {
    const char *tmp_str = to_string();
    length = strlen(tmp_str);
    data = String::allocate_and_copy(tmp_str, length + 1);
}

String::~String() { delete[] data; }

String &String::operator=(const char *str) {
    length = strlen(str);
    data = String::allocate_and_copy(str, length + 1);
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

String &String::as_string(const GenericString &other) {
    String *tmp = dynamic_cast<String *>(const_cast<GenericString *>(&other));
    if (tmp == nullptr) {
        throw std::bad_cast();
    }
    return *tmp;
