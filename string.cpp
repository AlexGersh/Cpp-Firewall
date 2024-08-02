#include "string.h"
#include "string-array.h"

char *String::allocate_and_copy(const char *data, int size) {
    char *str = new char[size + 1];
    strcpy(str, data);
    return str;
}

String::String() {
    this->length = 0;
    this->data = NULL;
}

String::String(const char *str) {
    int size = strlen(str);
    this->data = String::allocate_and_copy(str, size + 1);
    this->length = size;
}

String::String(const String &str) {
    const char *tmp_str = to_string();
    this->length = strlen(tmp_str);
    this->data = String::allocate_and_copy(tmp_str, this->length + 1);
}
