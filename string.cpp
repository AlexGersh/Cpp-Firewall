#include "string.h"
#include "string-array.h"
#include <cstring>

// implementing the private member
char *String::allocate_and_copy(const char *data, int size) {
    char *str = new char[size + 1];
    memcpy(str, data, size);
    str[size] = '\0'; // closing the string
    return str;
}

// getters
int String::get_length() const { return length; }

const char *String::get_data() const { return data; }

// implementing c-tors
String::String() : data(NULL), length(0) {};

String::String(const char *str = "") {
    // if no str provided, by default its an empty string and length will be 0
    length = strlen(str);
    data = String::allocate_and_copy(str, length);
}

String::String(const String &str_obj) {
    length = str_obj.get_length();
    data = String::allocate_and_copy(str_obj.get_data(), length);
}

// implementing d-tor
String::~String() { delete[] this->data; }

// implementing operator '='
String &String::operator=(const char *str) {
    length = strlen(str);
    data = String::allocate_and_copy(str, length);
    return *this;
}

// other methods
bool String::operator==(const char *other) const {
    return strcmp(this->data, other) == 0;
}
bool String::operator==(const GenericString &other) const {
    return strcmp(this->data, other.as_string().data);
}

const String &String::as_string() const { return (String &)*this; }

String &String::as_string() { return (String &)*this; }

StringArray String::split(const char *delimiters) const {
    // helpers
    char *cp = this->data;
    char *start = cp;
    char *tmp;
    StringArray sArr;

    while (*cp) {
        if ((*cp) == *delimiters) {
            tmp = allocate_and_copy(start, cp - start);
            String *s = new String(tmp);
            sArr.Add(*s);
            start = cp + 1;
            delete[] tmp;
        }
        cp++;
    }

    // for the last itteration we had (during while)
    tmp = allocate_and_copy(start, cp - start);
    String *s = new String(tmp);
    delete[] tmp;
    sArr.Add(*s);

    return sArr;
}

String &String::trim() {
    char *cp_start = this->data;
    char *cp_end = cp_start + strlen(cp_start) - 1;

    // find first non-space character
    while (*cp_start == ' ') {
        cp_start++;
    }
    // find last non-space character
    while (*cp_end == ' ') {
        cp_end--;
    }

    char *tmp = allocate_and_copy(cp_start, cp_end - cp_start + 1);
    String *s = new String(tmp);
    delete[] tmp;
    return *s;
}

int String::to_integer() const { return atoi(this->as_string().get_data()); }

// should be global
GenericString *make_string(const char *str) {

    GenericString *gs = new String(str);

    return gs;
}

// Only for testing. need to delete when use as SO
int main() {
    GenericString *s = make_string("test1");
    std::cout << s->as_string().get_data() << std::endl;
    return 0;
}
