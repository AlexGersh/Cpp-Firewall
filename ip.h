#ifndef IP_H
#define IP_H

#include "generic-field.h"
#include "string-array.h"
#include "string.h"

class IP : public GenericField {

  private:
    String ip_rule;
    String ip_name;
    String ip_value;

  public:
    IP();

    IP(const char *);
    IP(String &);
    IP(const IP &);
    ~IP();

    IP &operator=(const IP &);
    bool match(const GenericString &packet) const;

    bool is_mask(const GenericString &) const;
    static int get_ip_addr_int(const GenericString &);
};

#endif