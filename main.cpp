#include "input.h"
#include "port.h"
#include "ip.h"
#include "string-array.h"


int main(int argc,char** argv){


    std::cout<<"hello world"<<std::endl;
    //IP check- alex dont touch this please
    IP ip1=IP();
    IP ip2=IP("ip-src=122.0.0.0/8");
    String packet="src-ip=122.0.6.0  ,   src-port=67,dst-port=4,  dst-ip = 1.2.3.4";
    std::cout<<"is there match?"<<ip2.match(packet)<<std::endl;        

    
    
    
    //--------------------IP CHECK-----------------
  
}