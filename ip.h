#ifndef IP_H
#define IP_H

#include "generic-field.h"
#include "string.h"
#include "string-array.h"

class IP: public GenericField {

private:
    String ip_rule;
    String ip_name;
    String ip_value;
public:
    IP();

    IP(const char*);
    IP(String&);
    ~IP();

    bool match(const GenericString& packet) const;    

    bool is_mask(const GenericString&,const GenericString&) const  ;

};

#endif