#include "port.h"

// implementing c-tors
// default
Port::Port() {}

// #1 cpy c-tor
Port::Port(const char *cp) {
    port_rule = cp;
    StringArray string_array = port_rule.split("=");
    port_name = string_array[0].as_string().trim();

    String tmp = string_array[1].as_string().trim();
    StringArray tmp_string_array = tmp.split("-");
    port_range_start = tmp_string_array[0].as_string().to_integer();
    port_range_end = tmp_string_array[1].as_string().to_integer();
}

// #2 cpy c-tor, using the #1
Port::Port(String &s) : Port(s.get_data()) {};

// implementing d-tor
Port::~Port() {};

bool Port::match(const GenericString &packet) const {
    // tim meleh
}
