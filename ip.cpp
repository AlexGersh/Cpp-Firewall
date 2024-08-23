#include "ip.h"
#include <iostream>
IP::IP() : ip_rule() {};

IP::IP(const char *cp) : ip_rule(cp) {
    StringArray string_array = ip_rule.split("=");
    ip_name = string_array[0].as_string().trim();
    ip_value = string_array[1].as_string().trim();
    string_array.clear();
}

IP::IP(String &s) : IP(s.get_data()) {};
IP::IP(const IP &other)
    : ip_rule(other.ip_rule), ip_name(other.ip_name),
      ip_value(other.ip_value) {};
IP::~IP() {};

IP &IP::operator=(const IP &other) {
    ip_rule = other.ip_rule;
    ip_name = other.ip_name;
    ip_value = other.ip_value;
    return *this;
}

int IP::get_ip_addr_int(const GenericString &ip) {
    // seperate ip by .
    StringArray ip_field_array = ip.split(".");

    int ip_num = 0;
    const int shifter = 8;
    char curr_ip_num = 0;

    for (int i = 0; i < ip_field_array.size(); i++) {
        curr_ip_num = ip_field_array[i].as_string().to_integer();

        ip_num = ip_num << shifter;
        ip_num += curr_ip_num;
    }

    ip_field_array.clear();
    return ip_num;
}

bool IP::is_mask(const GenericString &field_ip) const {

    StringArray rule_addr_mask = ip_value.split("/");

    int ip_addr = get_ip_addr_int(rule_addr_mask[0]);
    int ip_field_addr = get_ip_addr_int(field_ip);

    int ip_mask = rule_addr_mask[1].as_string().to_integer();

    int mask = (~0u) << (32 - ip_mask);

    // mask only the relevant bits
    ip_addr = ip_addr & mask;
    ip_field_addr = ip_field_addr & mask;
    // wil and both ip's and mask to check if the same

    bool rt = !(ip_addr ^ ip_field_addr);
    rule_addr_mask.clear();
    return rt;
}

bool IP::match(const GenericString &packet) const {

    // spilt all packets to fields
    StringArray string_arr = packet.split(",");
    StringArray field;
    bool match_flag = true;
    // trim each field
    for (int i = 0; i < string_arr.size(); i++) {
        string_arr[i].trim();
    }
    // now we have string_arr=["sirc-p=6.6.6.6","src-port=67"...]

    // validate ip rules
    for (int i = 0; i < string_arr.size(); i++) {
        field = string_arr[i].split("=");
        if (ip_name == field[0].as_string().trim()) {
            if (!is_mask(field[1].as_string().trim())) {
                match_flag = false;
                return match_flag;
            }
        }
    }

    string_arr.clear();
    field.clear();
    return match_flag;
}
