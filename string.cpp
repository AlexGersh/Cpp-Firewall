#include "string.h"
#include "string-array.h"
#include <cstring>

char *String::allocate_and_copy(const char *data, int size) {
    char *str = new char[size + 1];
    memcpy(str, data,size);
    str[size]=0;
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
bool String::operator==(const GenericString &other) const{
    return strcmp(data,other.as_string().data);
}



const String &String::as_string() const { return (String&)*this; }

String &String::as_string() {  return (String&)*this; }

StringArray String::split(const char *delimiters) const{

    char* cp=this->data;
    char* start=cp;
    char*  tmp;
    StringArray sArr=StringArray();

    while(*cp)
    {
        if((*cp)==*delimiters)
        {
            tmp=allocate_and_copy(start,cp-start);
            String* s=new String(tmp);
            sArr.Add(*s);
            start=cp+1;
            delete tmp;
        }
        cp++;
    }
    tmp=allocate_and_copy(start,cp-start);
    String* s=new String(tmp);
    delete tmp;
    sArr.Add(*s);
    
    return sArr;
}

String& String::trim()
{
    String* s=new String("hello");
    return *s;
} 

int String::to_integer() const{
    return atoi(this->as_string().get_data());
}

/*
// should be global
GenericString *make_string(const char *str) {

    return nullptr;
}
*/

int main()
{
    String s=String("one,two,three");
    StringArray arr=s.split(",");
    for(int i=0;i<3;i++)
    {
        std::cout<<arr[i].as_string().get_data()<<std::endl;
    }
    return 0;
}
