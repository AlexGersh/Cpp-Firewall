#include "port.h"

// implementing c-tors
Port::Port() {
    port_rule = String();
    port_name = String();
    port_range_start = String();
    port_range_end = String();
}

Port::Port(const char *cp) {
    port_rule = cp;
    StringArray string_array = port_rule.split("=");
    port_name = string_array[0].as_string().trim();

    String tmp = string_array[1].as_string().trim();
    StringArray tmp_string_array = tmp.split("-");
    port_range_start = tmp_string_array[0].as_string();
    port_range_end = tmp_string_array[1].as_string();
}
