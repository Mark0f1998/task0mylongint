#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    /*mylonginteger a,b;
    a.read_longinteger();
    while(true)
    {
        std::cout<<"current summ= ";
        a.write_longinteger();
        std::cout<<"\nenter next longinteger\n";
        b.read_longinteger();
        a+=b;
    }*/
    mylonginteger a,b("12321412421");
    a.read_longinteger();
    b=a;
    b.write_longinteger();

}

