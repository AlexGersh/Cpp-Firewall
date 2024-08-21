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
Port::Port(const String &s) : Port(s.get_data()) {}

// #3 cpy c-tor
Port::Port(const Port &port)
    : port_rule(port.port_rule), port_name(port.port_name),
      port_range_start(port.port_range_start),
      port_range_end(port.port_range_end) {};

// d-tor, nothing special
Port::~Port() {}

Port &Port::operator=(const Port &other) {
    port_rule = other.port_rule;
    port_name = other.port_name;
    port_range_start = other.port_range_start;
    port_range_end = other.port_range_end;
    return *this;
}

bool Port::right_port(const GenericString &field_port) const {
    String port_str = field_port.as_string();
    short port_int = port_str.trim().to_integer();

    // validate
    if (port_int >= this->port_range_start && port_int <= port_range_end)
        return true;
    // else
    return false;
}

bool Port::match(const GenericString &packet) const {
    // split all packets to fields
    StringArray string_arr = packet.split(",");
    StringArray field;
    bool match_flag = true;

    // trim each field
    for (int i = 0; i < string_arr.size(); i++) {
        string_arr[i].trim();
    }
    // now string_arr={"src-ip=6.6.6.6","src-port=67",...}

    // checking
    for (int i = 0; i < string_arr.size(); i++) {
        field = string_arr[i].split("=");

        if (port_name == field[0].as_string().trim()) {
            if (!right_port(field[1].as_string().trim())) {
                match_flag = false;
                return match_flag;
            }
        }
    }

    return match_flag;
}
