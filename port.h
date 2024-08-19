#ifndef PORT_H
#define PORT_H

#include "generic-field.h"
#include "string.h"
#include "string-array.h"

class PORT : public GenericField
{


private:
public:
    PORT();
    PORT(const char *);
    ~PORT();

    bool match(const GenericString& packet) const;    

    //bool is_mask(String&,String&);

};






#endif