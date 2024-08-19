#include "ip.h"

IP::IP() : ip_rule() {};

IP::IP(const char *cp) : ip_rule(cp) {
    StringArray string_array = ip_rule.split("=");
    ip_name = string_array[0].as_string().trim();
    ip_value = string_array[1].as_string().trim();
}

IP::IP(String &s) : IP(s.get_data()) {};

IP::~IP(){};

bool IP::is_mask(const GenericString &field_ip) const {
    
    StringArray rule_addr_mask=ip_rule.split("/");
    
    int ip_addr=rule_addr_mask[0].as_string().to_integer();
    int ip_mask=rule_addr_mask[1].as_string().to_integer();

    int mask=1<<ip_mask;
    return ip_addr&&(field_ip.as_string().to_integer()&&mask);


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
    // now we have string_arr=["src-ip=6.6.6.6",src-port=67"...]

    // validate ip rules
    for (int i = 0; i < string_arr.size(); i++) {
        field = string_arr[i].split("=");

        if (ip_name == field[0].as_string().trim()) {
            if (!is_mask(field[1]))
                match_flag = false;
        }
    }

    return match_flag;
}
