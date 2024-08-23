#include "input.h"
#include "ip.h"
#include "port.h"
#include "string.h"
#include "string-array.h"

#include "generic-field.h"

int main(int argc, char **argv) {
    
    GenericField* gf=0;

   /* StringArray test1;
    String s="hello";
    test1.Add(s);
    StringArray test2=test1;
*/
    if(argc!=2)
    {
        std::cout<<"Error: need pass only one argument";
    }

    String rule=String(argv[1]);
    if(rule.locate("port"))
    {
        gf=new Port(rule);
    }
    else if(rule.locate("ip"))
    {
        gf=new IP(rule);
    }
    else
    {
        std::cout<<"unvalid argument"<<std::endl;       
    }

    parse_input(*gf);

    delete gf;


}