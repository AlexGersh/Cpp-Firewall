#include "input.h"
#include "ip.h"
#include "port.h"
#include "string-array.h"

int main(int argc, char **argv) {

    std::cout << "IP check" << std::endl;
    // IP check- alex dont touch this please
    IP ip1 = IP();
    IP ip2 = IP("ip-src=122.0.0.0/8");
    String packet1 = "ip-src=121.0.6.0,src-port=22,dst-port=25,dst-ip =1.2.3.4";
    String packet2 = "ip-src=122.0.6.0,src-port=120.1.0.21,dst-port=122.2.2.2,"
                     "dst-ip =1.2.3.4";
    std::cout << "is there match?\n" << ip2.match(packet1) << std::endl;
    std::cout << "is there match?\n" << ip2.match(packet2) << std::endl;

    //--------------------IP CHECK-----------------

    std::cout << "Port check" << std::endl;
    Port port1 = Port("dest-port=22-22");
    Port port2 = Port("src-port=23-25");
    std::cout << "is there match-port?\n" << port1.match(packet1) << std::endl;
    std::cout << "is there match-port?\n" << port2.match(packet1) << std::endl;
    std::cout << "is there match-port?\n" << port1.match(packet2) << std::endl;
    std::cout << "is there match-port?\n" << port2.match(packet2) << std::endl;
}