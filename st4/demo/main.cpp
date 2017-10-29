#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    mylonginteger a("00000123");
    a.write_longinteger();
    mylonginteger b("214");
    b.write_longinteger();
}
/*
  mylonginteger a,b;
    a.read_longinteger();
    while(true)
    {
        std::cout<<"current summ= ";
        a.write_longinteger();
        b.read_longinteger();
        a+=b;
    }
    */
