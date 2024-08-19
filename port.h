#ifndef PORT_H
#define PORT_H

#include "generic-field.h"
#include "string-array.h"
#include "string.h"

class PORT : public GenericField {

  private:
  public:
    PORT();
    PORT(const char *);
    ~PORT();

    bool match(const GenericString &packet) const;

    // bool is_mask(String&,String&);
};

#endif