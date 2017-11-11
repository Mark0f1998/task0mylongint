#include "../common/longarithm.hpp"
using namespace mli;
int main()
{
    mylonginteger a,b;
    a.read_longinteger();
    //std::cout << a;
    //std::cout<<'huy\n';
    while(true)
    {
        std::cout<<"current summ= ";
        std::cout<<a;
        std::cout<<"\nenter next longinteger\n";
        b.read_longinteger();
        a+=b;
    }
}

